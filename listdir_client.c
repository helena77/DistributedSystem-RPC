/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "listdir.h"
#include <errno.h>

extern int errno;

void
dir_list_prog_1(char *host, char *path)
{
	CLIENT *clnt;
	readdir_ret  *result_1;
	namelist list;

#ifndef	DEBUG
	clnt = clnt_create (host, DIR_LIST_PROG, DIR_LIST_VERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */
	result_1 = readdir_1(&path, clnt);
	if (result_1 == (readdir_ret *) NULL) {
		clnt_perror (clnt, "call failed");
		exit(1);
	}
	if (result_1->err != 0) {
		errno = result_1->err;
		perror(path);
		exit(1);
	}
	printf("The dirctory entries are: \n");
	for (list = result_1->readdir_ret_u.list; list != NULL; list = list->next) {
		printf("%s\n", list->name);
	}
	clnt_freeres(clnt, (xdrproc_t)xdr_readdir_ret, (char *)&result_1);
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;
	char *path;

	if (argc < 3) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	path = argv[2];
	dir_list_prog_1 (host, path);
	exit (0);
}
