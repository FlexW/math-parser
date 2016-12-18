#include "calc.h"

char buffer[1024];
char output[30]; // TODO: Must be zeroed

void interactive_mode ( );

int main ( int argc, const char *argv[] ) {
  FILE *file;
  int j = 1;
  char *exp;
  
  if (argc < 2) {
    printf( "Please type at least one option.\n\n-h for help\n");
    exit( 0 );
  }

  for (int i = 1; i < argc; i++) {
    
    if (strcmp( "-h", argv[i] ) == 0  ||
	strcmp( "--help", argv[i] ) == 0 ) {
      // TODO: Implement help.
      printf( HELPTEXT );
      exit( 0);
    }

    // File
    else if (strcmp( "-f", argv[i] ) == 0 ||
	     strcmp( "--file", argv[i] ) == 0) {
      file = fopen ( argv[i + 1], "r" );

      while ( fgets ( buffer, 1024, file ) ) {

	calculate( buffer, output );
	printf( "%i >> %s\n", j, output );
	j++;
      }
    }

    // Direct mode
    else if (strcmp( "-d", argv[i] ) == 0 ||
	     strcmp( "--direct", argv[i] ) == 0) {

      calculate( argv[i + 1], output );
      printf( ">> %s\n", output );

      exit( 0 );
    }

    //Interactive mode
    else if (strcmp( "-i", argv[i] ) == 0 ||
	     strcmp( "--interactive", argv[i] ) == 0) {
      interactive_mode( );
    }
    else
      // TODO: Error handling
      ;
  }

  return 0;
}

void interactive_mode ( ) {
  
  while (true) {
    printf( "<< " );
    if (NULL == fgets( buffer, 1024, stdin ))
      // TODO: Impliment error handling
      ;
    calculate( buffer, output );
    printf( ">> %s\n", output );
  }
}