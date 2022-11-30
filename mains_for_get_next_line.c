/* mains for get_next_line */

/* nl */
int main()
{
	int fd;
	char *res;
	const char *expectedres;
	
	fd = open("./gnlTester/files/nl", O_RDWR);
	res = get_next_line(fd);
	expectedres = "\n";
	if (!strcmp(res, expectedres))
		printf("right : %s---------\n", res);
	else
		printf("%s \ninstead of \n%s\n---------\n", res, expectedres);
	close(fd);
}

/* multiple line no new line */
int main()
{
    int fd;
    char *res;
	const char *expectedres;

    fd = open("./gnlTester/files/multiple_line_no_nl", O_RDWR);
	res = get_next_line(fd);
	expectedres = "01234567890123456789012345678901234567890\n";
	if (!strcmp(res, expectedres))
		printf("right : %s\n---------\n", res);
	else
		printf("%s \ninstead of \n%s\n---------\n", res, expectedres);

	res = get_next_line(fd);
	expectedres = "987654321098765432109876543210987654321098\n";
	if (!strcmp(res, expectedres))
		printf("right : %s\n---------\n", res);
	else
		printf("%s \ninstead of \n%s\n---------\n", res, expectedres);
		
	res = get_next_line(fd);
	expectedres = "0123456789012345678901234567890123456789012\n";
	if (!strcmp(res, expectedres))
		printf("right : %s\n---------\n", res);
	else
		printf("%s \ninstead of \n%s\n---------\n", res, expectedres);

    res = get_next_line(fd);
	expectedres = "987654321098765432109876543210987654321098\n";
	if (!strcmp(res, expectedres))
		printf("right : %s\n---------\n", res);
	else
		printf("%s \ninstead of \n%s\n---------\n", res, expectedres);

    res = get_next_line(fd);
	expectedres = "01234567890123456789012345678901234567890";
	if (!strcmp(res, expectedres))
		printf("right : %s\n---------\n", res);
	else
		printf("%s \ninstead of \n%s\n---------\n", res, expectedres);
}

/* 41_with_nl */
int main()
{
    int fd;
    char *res;
	const char *expectedres;

    fd = open("./gnlTester/files/41_with_nl", O_RDWR);
	res = get_next_line(fd);
	expectedres = "0123456789012345678901234567890123456789\n";
	if (!strcmp(res, expectedres))
		printf("right : %s\n---------\n", res);
	else
		printf("%s \ninstead of \n%s\n---------\n", res, expectedres);
	free(res);
	res = get_next_line(fd);
	expectedres = "0";
	if (!strcmp(res, expectedres))
		printf("right : %s\n---------\n", res);
	else
		printf("%s \ninstead of \n%s\n---------\n", res, expectedres);
	free(res);
}

