#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <asm/uaccess.h>	/* for put_user */
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/slab.h>

#include "helloworld.h"

MODULE_LICENSE("GPL");

struct cdev my_cdev;
int my_major;
static struct class *my_class;
dev_t first;

static char Message[100];

static int my_open(struct inode *i,struct file *f)
{
	printk(KERN_INFO "in my open...\n");
	return 0;
}

static int my_close(struct inode *i,struct file *f)
{
	printk(KERN_INFO "in my close...\n");
	return 0;
}


static ssize_t my_read(struct file *f, char *buff, size_t len,loff_t *f_pos)
{
	
	char msg[20] = "Hello SJ_read\0";
    printk(KERN_ALERT "The Read operation called\r\n");
    copy_to_user( buff, msg, sizeof(msg) );
      

	return(sizeof(msg));
}

static ssize_t my_write(struct file *f, const char *buff, size_t len,loff_t *offset)
{

	char msg[20];
	printk(KERN_ALERT "in my write\n");

	if ( 0 != copy_from_user( msg, buff, sizeof(msg) ))
        {
		printk(KERN_ALERT "Copy_from_user failed !!\r\n");
        }

	printk(KERN_ALERT "msg received: %s\n",msg);

	return(sizeof(msg));
}

int my_ioctl(struct inode *i,struct file *f,unsigned int ioctl_num,unsigned long ioctl_param)
{
	int idx;
	char *temp;
	char ch;
	printk(KERN_ALERT "my_ioctl ioctl_num: %d\n",ioctl_num);
	switch(ioctl_num)
	{
		case IOCTL_SET_MSG:
			/*temp = (char *)ioctl_param;
			get_user(ch, temp);

			for (idx = 0; ch && idx < 100; idx++, temp++)
				get_user(ch, temp);

			my_write(f, (char *)ioctl_param, idx, 0);*/
			printk(KERN_ALERT "In IOCTL_SET_MSG..\n");
			break;

		case IOCTL_GET_MSG:
			printk(KERN_ALERT "In IOCTL_GET_MSG..\n");
			/*idx = my_read(f, (char *)ioctl_param, 99, 0);
			put_user('\0', (char *)ioctl_param + idx);*/
		break;

		case IOCTL_GET_NTH_BYTE:
		//	return Message[ioctl_param];
			printk(KERN_ALERT "In nth byte ioctl..\n");
		break;	
	}

	return 0;
}


static struct file_operations my_fops = {
.owner = THIS_MODULE,
.open = my_open,
.release = my_close,
.unlocked_ioctl = my_ioctl,
.read = my_read,
.write = my_write,
};

static int hello_init(void)
{
	int res;
        dev_t curr_dev;
	printk(KERN_ALERT "Hello world \n");
	res = alloc_chrdev_region(&first,0,1,"mydevice");
	if(res)
	{
		printk(KERN_INFO "device allocation failed\n");
		return -1;
	}
        
	
	if ((my_class = class_create(THIS_MODULE, "chardrv")) == NULL)    //$ls /sys/class
	{
		unregister_chrdev_region(first, 1);
		return -1;
	}

        curr_dev = MKDEV(MAJOR(first), MINOR(first));

	if (device_create(my_class, NULL, curr_dev, NULL, "mydev") == NULL) //$ls /dev/
	{

		class_destroy(my_class);
		unregister_chrdev_region(first, 1);
		return -1;
	}

	
	cdev_init(&my_cdev,&my_fops);

	res = cdev_add(&my_cdev,curr_dev,1);
	if(res)
	{
		printk (KERN_NOTICE "Couldn't add cdev");
		device_destroy(my_class,first);
		class_destroy(my_class);
		unregister_chrdev_region(first, 1);
		return -1;
	}

        


	return 0;
}

static void hello_exit(void)
{
	cdev_del(&my_cdev);
	device_destroy(my_class,first);
	class_destroy(my_class);
	unregister_chrdev_region(first, 1);
	printk(KERN_ALERT "Bye \n");
}

module_init(hello_init);
module_exit(hello_exit);
