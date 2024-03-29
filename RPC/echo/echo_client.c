/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "echo.h"


void
echoprg_1(char *host, char *str)
{
	CLIENT *clnt;
	char * *result_1;
	char * echo_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, ECHOPRG, ECHOER, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */
	echo_1_arg=str;
	result_1 = echo_1(&echo_1_arg, clnt);
	if (result_1 == (char **) NULL) {
		clnt_perror (clnt, "call failed");
	}
	else
	printf("%s",*(result_1));
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	echoprg_1 (host,argv[2]);
exit (0);
}
