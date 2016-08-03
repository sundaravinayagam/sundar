/** This program is to print the input  string  to stdout which was stored using a variable called 'input_string' 
  Here there are two ways are possible.
  1.Using printf function
  2.Usinf fprintf function
Usage of printf and fprintf function:
If you need to print to a particular output stream, use fprintf.

If you need to show an error message, use fprintf w/ stderr

If you're developing a command-line executable and just want to display something to the user, use printf.

refer link : http://stackoverflow.com/questions/13261879/which-is-preferable-printf-or-fprintf 
**/
  


int main() {
    // Declare a variable named 'input_string' to hold our input.
    char input_string[105]; 

    
    // Read a full line of input from stdin and save it to our variable, input_string.
    scanf("%[^\n]", input_string); 
    // Print a string literal saying "Hello, World." to stdout using printf.
    printf("Hello, World.\n");
    fprintf(stdout,"%s",input_string);
    
    // TODO: Write a line of code here that prints the contents of input_string to stdout.
    
    return 0;
}
