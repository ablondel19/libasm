/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 12:34:15 by ablondel          #+#    #+#             */
/*   Updated: 2021/02/21 14:24:13 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

extern size_t	ft_strlen(const char*);
extern char		*ft_strcpy(char*, const char*);
extern int		ft_strcmp(const char*, const char*);
extern ssize_t	ft_write(int, const void*, size_t);
extern ssize_t	ft_read(int, void*, size_t);
extern char		*ft_strdup(const char*);

int		main(void)
{
	int m_res = 0;
	int v_res = 0;
	printf("%s-------------------------------------------------------------------------------\n", KGRN);
	printf("%s-------------------------------TEST FT_STRLEN----------------------------------\n", KGRN);
	printf("%s-------------------------------------------------------------------------------\n", KGRN);


	printf("%s\n----------->>>chaine vide<<<-----------\n\n", KYEL);
	printf("%sLE MIEN = %zu\n",KCYN, ft_strlen(""));
	printf("%sLE VRAI = %zu\n",KBLU,    strlen(""));
	

	printf("%s\n----------->>>chaine longue<<<-----------\n\n", KYEL);
	printf("%sLE MIEN = %zu\n",KCYN, ft_strlen("aaabbbcccdddeeefffggghhhiiijjjkkklllmmmnnnooopppqqqrrrssstttuuuvvvwwwxxxyyyzzz\
	aaabbbcccdddeeefffggghhhiiijjjkkklllmmmnnnooopppqqqrrrssstttuuuvvvwwwxxxyyyzzz\
	aaabbbcccdddeeefffggghhhiiijjjkkklllmmmnnnooopppqqqrrrssstttuuuvvvwwwxxxyyyzzz\
	aaabbbcccdddeeefffggghhhiiijjjkkklllmmmnnnooopppqqqrrrssstttuuuvvvwwwxxxyyyzzz\
	aaabbbcccdddeeefffggghhhiiijjjkkklllmmmnnnooopppqqqrrrssstttuuuvvvwwwxxxyyyzzz\
	aaabbbcccdddeeefffggghhhiiijjjkkklllmmmnnnooopppqqqrrrssstttuuuvvvwwwxxxyyyzzz\
	aaabbbcccdddeeefffggghhhiiijjjkkklllmmmnnnooopppqqqrrrssstttuuuvvvwwwxxxyyyzzz"));
	printf("%sLE VRAI = %zu\n",KBLU,    strlen("aaabbbcccdddeeefffggghhhiiijjjkkklllmmmnnnooopppqqqrrrssstttuuuvvvwwwxxxyyyzzz\
	aaabbbcccdddeeefffggghhhiiijjjkkklllmmmnnnooopppqqqrrrssstttuuuvvvwwwxxxyyyzzz\
	aaabbbcccdddeeefffggghhhiiijjjkkklllmmmnnnooopppqqqrrrssstttuuuvvvwwwxxxyyyzzz\
	aaabbbcccdddeeefffggghhhiiijjjkkklllmmmnnnooopppqqqrrrssstttuuuvvvwwwxxxyyyzzz\
	aaabbbcccdddeeefffggghhhiiijjjkkklllmmmnnnooopppqqqrrrssstttuuuvvvwwwxxxyyyzzz\
	aaabbbcccdddeeefffggghhhiiijjjkkklllmmmnnnooopppqqqrrrssstttuuuvvvwwwxxxyyyzzz\
	aaabbbcccdddeeefffggghhhiiijjjkkklllmmmnnnooopppqqqrrrssstttuuuvvvwwwxxxyyyzzz"));


	printf("%s\n----------->>>chaine de 10<<<-----------\n\n", KYEL);
	printf("%sLE MIEN = %zu\n",KCYN, ft_strlen("abcdefghij"));
	printf("%sLE VRAI = %zu\n",KBLU,    strlen("abcdefghij"));
	

	printf("%s\n----------->>>chaine de 15<<<-----------\n\n", KYEL);
	printf("%sLE MIEN = %zu\n",KCYN, ft_strlen("abcdefghijklmno"));
	printf("%sLE VRAI = %zu\n",KBLU,    strlen("abcdefghijklmno"));


	printf("\n\n");
	printf("%s-------------------------------------------------------------------------------\n", KGRN);
	printf("-------------------------------TEST FT_STRCPY----------------------------------\n");
	printf("-------------------------------------------------------------------------------\n");

	printf("%s\n----------->>>chaine vide<<<-----------\n\n", KYEL);
	char mdst1[] = "";
	printf("%sLE MIEN = %s\n",KCYN, ft_strcpy(mdst1, ""));
	char rdst1[] = "";
	printf("%sLE VRAI = %s\n",KBLU,    strcpy(rdst1, ""));


	printf("%s\n----------->>>chaine longue<<<-----------\n\n", KYEL);
	char mdst2[] = "aaabbbcccdddeeefffggghhhiiijjjkkklllmmmnnnooopppqqqrrrssstttuuuvvvwwwxxxyyyzzz\
aaabbbcccdddeeefffggghhhiiijjjkkklllmmmnnnooopppqqqrrrssstttuuuvvvwwwxxxyyyzzz\
aaabbbcccdddeeefffggghhhiiijjjkkklllmmmnnnooopppqqqrrrssstttuuuvvvwwwxxxyyyzzz\
aaabbbcccdddeeefffggghhhiiijjjkkklllmmmnnnooopppqqqrrrssstttuuuvvvwwwxxxyyyzzz\
aaabbbcccdddeeefffggghhhiiijjjkkklllmmmnnnooopppqqqrrrssstttuuuvvvwwwxxxyyyzzz\
aaabbbcccdddeeefffggghhhiiijjjkkklllmmmnnnooopppqqqrrrssstttuuuvvvwwwxxxyyyzzz\
aaabbbcccdddeeefffggghhhiiijjjkkklllmmmnnnooopppqqqrrrssstttuuuvvvwwwxxxyyyzzz";
	printf("%sLE MIEN = %s\n",KCYN, ft_strcpy(mdst2, \
"zzzyyyxxxwwwvvvuuutttsssrrrqqqpppooonnnmmmlllkkkjjjiiihhhgggfffeeedddcccbbbaaa\
zzzyyyxxxwwwvvvuuutttsssrrrqqqpppooonnnmmmlllkkkjjjiiihhhgggfffeeedddcccbbbaaa\
zzzyyyxxxwwwvvvuuutttsssrrrqqqpppooonnnmmmlllkkkjjjiiihhhgggfffeeedddcccbbbaaa\
zzzyyyxxxwwwvvvuuutttsssrrrqqqpppooonnnmmmlllkkkjjjiiihhhgggfffeeedddcccbbbaaa\
zzzyyyxxxwwwvvvuuutttsssrrrqqqpppooonnnmmmlllkkkjjjiiihhhgggfffeeedddcccbbbaaa\
zzzyyyxxxwwwvvvuuutttsssrrrqqqpppooonnnmmmlllkkkjjjiiihhhgggfffeeedddcccbbbaaa\
zzzyyyxxxwwwvvvuuutttsssrrrqqqpppooonnnmmmlllkkkjjjiiihhhgggfffeeedddcccbbbaaa"));
	char rdst2[] = "aaabbbcccdddeeefffggghhhiiijjjkkklllmmmnnnooopppqqqrrrssstttuuuvvvwwwxxxyyyzzz\
aaabbbcccdddeeefffggghhhiiijjjkkklllmmmnnnooopppqqqrrrssstttuuuvvvwwwxxxyyyzzz\
aaabbbcccdddeeefffggghhhiiijjjkkklllmmmnnnooopppqqqrrrssstttuuuvvvwwwxxxyyyzzz\
aaabbbcccdddeeefffggghhhiiijjjkkklllmmmnnnooopppqqqrrrssstttuuuvvvwwwxxxyyyzzz\
aaabbbcccdddeeefffggghhhiiijjjkkklllmmmnnnooopppqqqrrrssstttuuuvvvwwwxxxyyyzzz\
aaabbbcccdddeeefffggghhhiiijjjkkklllmmmnnnooopppqqqrrrssstttuuuvvvwwwxxxyyyzzz\
aaabbbcccdddeeefffggghhhiiijjjkkklllmmmnnnooopppqqqrrrssstttuuuvvvwwwxxxyyyzzz";
	printf("%sLE VRAI = %s\n",KBLU,    strcpy(rdst2, \
					"zzzyyyxxxwwwvvvuuutttsssrrrqqqpppooonnnmmmlllkkkjjjiiihhhgggfffeeedddcccbbbaaa\
zzzyyyxxxwwwvvvuuutttsssrrrqqqpppooonnnmmmlllkkkjjjiiihhhgggfffeeedddcccbbbaaa\
zzzyyyxxxwwwvvvuuutttsssrrrqqqpppooonnnmmmlllkkkjjjiiihhhgggfffeeedddcccbbbaaa\
zzzyyyxxxwwwvvvuuutttsssrrrqqqpppooonnnmmmlllkkkjjjiiihhhgggfffeeedddcccbbbaaa\
zzzyyyxxxwwwvvvuuutttsssrrrqqqpppooonnnmmmlllkkkjjjiiihhhgggfffeeedddcccbbbaaa\
zzzyyyxxxwwwvvvuuutttsssrrrqqqpppooonnnmmmlllkkkjjjiiihhhgggfffeeedddcccbbbaaa\
zzzyyyxxxwwwvvvuuutttsssrrrqqqpppooonnnmmmlllkkkjjjiiihhhgggfffeeedddcccbbbaaa"));


	printf("%s\n----------->>>chaine de 10<<<-----------\n\n", KYEL);
	char mdst3[] = "abcdefghijxxx";
	printf("%sLE MIEN = %s\n",KCYN, ft_strcpy(mdst3, "jihgfedcba"));
	char rdst3[] = "abcdefghijxxx";
	printf("%sLE VRAI = %s\n",KBLU,    strcpy(rdst3, "jihgfedcba"));


	printf("%s\n----------->>>chaine de 15<<<-----------\n\n", KYEL);
	char mdst4[] = "abcdefghijklmno";
	printf("%sLE MIEN = %s\n",KCYN, ft_strcpy(mdst4, "onmlkjihgfedcba"));
	char rdst4[] = "abcdefghijklmno";
	printf("%sLE VRAI = %s\n",KBLU,    strcpy(rdst4, "onmlkjihgfedcba"));


	printf("\n\n");
	printf("%s-------------------------------------------------------------------------------\n", KGRN);
	printf("-------------------------------TEST FT_STRCMP----------------------------------\n");
	printf("-------------------------------------------------------------------------------\n");

	printf("%s\n----------->>>2 chaines vide<<<-----------\n\n", KYEL);
	printf("%sLE MIEN = %d\n", KCYN, ft_strcmp("", ""));
	printf("%sLE VRAI = %d\n", KBLU,    strcmp("", ""));

	printf("%s\n----------->>>chaine vide en 1e arg<<<-----------\n\n", KYEL);
	printf("%sLE MIEN = %d\n", KCYN, ft_strcmp("", "abcdef"));
	printf("%sLE VRAI = %d\n", KBLU,    strcmp("", "abcdef"));

	printf("%s\n----------->>>chaine vide en 2er arg<<<-----------\n\n", KYEL);
	printf("%sLE MIEN = %d\n", KCYN, ft_strcmp("abcdef", ""));
	printf("%sLE VRAI = %d\n", KBLU,    strcmp("abcdef", ""));

	printf("%s\n----------->>>2 chaines egales<<<-----------\n\n", KYEL);
	printf("%sLE MIEN = %d\n", KCYN, ft_strcmp("abcdef", "abcdef"));
	printf("%sLE VRAI = %d\n", KBLU,    strcmp("abcdef", "abcdef"));

	printf("%s\n----------->>>2 chaines differentes<<<-----------\n\n", KYEL);
	printf("%sLE MIEN = %d\n", KCYN, ft_strcmp("abcdef", "fedcba"));
	printf("%sLE VRAI = %d\n", KBLU,    strcmp("abcdef", "fedcba"));

	printf("%s\n----------->>>2 chaines differentes en inverse<<<-----------\n\n", KYEL);
	printf("%sLE MIEN = %d\n", KCYN, ft_strcmp("fedcba", "abcdef"));
	printf("%sLE VRAI = %d\n", KBLU,    strcmp("fedcba", "abcdef"));

	printf("\n\n");
	printf("%s-------------------------------------------------------------------------------\n", KGRN);
	printf("-------------------------------TEST FT_WRITE-----------------------------------\n");
	printf("-------------------------------------------------------------------------------\n");

	

	printf("%s\n----------->>>ft_write sur stdout 1<<<-----------%s\n\n", KYEL, KCYN);
	
	errno = 0;
	m_res = ft_write(1, "abcdefghij\n", 11); printf("%sLE MIEN <errno = %d> <return = %d>%s\n",KCYN, errno, m_res, KBLU);
	v_res = write(1, "abcdefghij\n", 11); printf("%sLE VRAI <errno = %d> <return = %d>\n",KBLU, errno, v_res);

	printf("%s\n----------->>>ft_write sur stderr 2<<<-----------%s\n\n", KYEL, KCYN);
	errno = 0;
	m_res = ft_write(2, "abcdefghij\n", 11); printf("%sLE MIEN <errno = %d> <return = %d>%s\n",KCYN, errno, m_res, KBLU);
	v_res = write(2, "abcdefghij\n", 11); printf("%sLE VRAI <errno = %d> <return = %d>\n",KBLU, errno, v_res);

	printf("%s\n----------->>>ft_write sur fd 30<<<-----------\n\n", KYEL);
	
	errno = 0;
	m_res = ft_write(30, "abcdefghij\n", 11); printf("%sLE MIEN <errno = %d> <return = %d>\n",KCYN, errno, m_res);
	v_res = write(30, "abcdefghij\n", 11); printf("%sLE VRAI <errno = %d> <return = %d>\n",KBLU, errno, v_res);

	printf("%s\n----------->>>ft_write sur fd -1<<<-----------\n\n", KYEL);
	
	errno = 0;
	m_res = ft_write(-1, "abcdefghij\n", 11); printf("%sLE MIEN <errno = %d> <return = %d>\n",KCYN, errno, m_res);
	v_res = write(-1, "abcdefghij\n", 11); printf("%sLE VRAI <errno = %d> <return = %d>\n",KBLU, errno, v_res);
	
	errno = 0;
	printf("%s\n----------->>>ft_write sur fd du fichier test_ft_write.txt<<<-----------\n\n", KYEL);
	int fd1 = open("test_ft_write.txt", O_CREAT | O_RDWR, 0777);
	int fd2 = open("test_write.txt", O_CREAT | O_RDWR, 0777);
	m_res = ft_write(fd1, "abcdefghij", 10); printf("%sLE MIEN <errno = %d> <return = %d>\n",KCYN, errno, m_res);
	v_res = write(fd2, "abcdefghij", 10); printf("%sLE VRAI <errno = %d> <return = %d>\n",KBLU, errno, v_res);
	close(fd1);
	close(fd2);
	
	printf("\n\n");
	printf("%s-------------------------------------------------------------------------------\n", KGRN);
	printf("-------------------------------TEST FT_READ------------------------------------\n");
	printf("-------------------------------------------------------------------------------\n");

	printf("%s\n----------->>>ft_read sur stdin 0<<<-----------\n\n", KYEL);
	errno = 0;
	printf("%sTest independant\n", KCYN);
	//m_res = ft_read(0, "abcdefghij\n", 11); printf("LE MIEN <errno = %d> <return = %d>\n", errno, m_res);
	//v_res = read(0, "abcdefghij\n", 11); printf("LE VRAI <errno = %d> <return = %d>\n", errno, v_res);

	printf("%s\n----------->>>ft_read sur fichier<<<-----------\n\n", KYEL);
	errno = 0;
	fd1 = open("test_ft_write.txt", O_RDONLY);
	fd2 = open("test_write.txt", O_RDONLY);
	char mbuf[11];
	char rbuf[11];
	m_res = ft_read(fd1, mbuf, 11); printf("%sLE MIEN <errno = %d> <buf = [%s]> <return = %d>\n",KCYN, errno, mbuf, m_res);
	v_res = read(fd2, rbuf, 11); printf("%sLE VRAI <errno = %d> <buf = [%s]> <return = %d>\n",KBLU, errno, rbuf, v_res);
	close(fd1);
	close(fd2);

	printf("%s\n----------->>>ft_read sur fd 30<<<-----------\n\n", KYEL);
	errno = 0;
	char mbuf1[11];
	char rbuf1[11];
	m_res = ft_read(30, mbuf1, 11); printf("%sLE MIEN <errno = %d> <return = %d>\n",KCYN,  errno, m_res);
	v_res = read(30, rbuf1, 11); printf("%sLE VRAI <errno = %d> <return = %d>\n",KBLU,  errno, v_res);

	printf("\n\n");
	printf("%s-------------------------------------------------------------------------------\n", KGRN);
	printf("-------------------------------TEST FT_STRDUP----------------------------------\n");
	printf("-------------------------------------------------------------------------------\n");

	printf("%s\n----------->>>chaine vide<<<-----------\n\n", KYEL);
	char ddst1[] = "";
	printf("%sLE MIEN = %s\n", KCYN, ft_strdup(ddst1));
	char ddst2[] = "";
	printf("%sLE VRAI = %s\n",KBLU,    strdup(ddst2));


	printf("%s\n----------->>>chaine longue<<<-----------\n\n", KYEL);
	char ddst3[] = "aaabbbcccdddeeefffggghhhiiijjjkkklllmmmnnnooopppqqqrrrssstttuuuvvvwwwxxxyyyzzz\
aaabbbcccdddeeefffggghhhiiijjjkkklllmmmnnnooopppqqqrrrssstttuuuvvvwwwxxxyyyzzz\
aaabbbcccdddeeefffggghhhiiijjjkkklllmmmnnnooopppqqqrrrssstttuuuvvvwwwxxxyyyzzz\
aaabbbcccdddeeefffggghhhiiijjjkkklllmmmnnnooopppqqqrrrssstttuuuvvvwwwxxxyyyzzz\
aaabbbcccdddeeefffggghhhiiijjjkkklllmmmnnnooopppqqqrrrssstttuuuvvvwwwxxxyyyzzz\
aaabbbcccdddeeefffggghhhiiijjjkkklllmmmnnnooopppqqqrrrssstttuuuvvvwwwxxxyyyzzz\
aaabbbcccdddeeefffggghhhiiijjjkkklllmmmnnnooopppqqqrrrssstttuuuvvvwwwxxxyyyzzz";
	printf("%sLE MIEN = %s\n", KCYN, ft_strdup(ddst3));
	char ddst4[] = "aaabbbcccdddeeefffggghhhiiijjjkkklllmmmnnnooopppqqqrrrssstttuuuvvvwwwxxxyyyzzz\
aaabbbcccdddeeefffggghhhiiijjjkkklllmmmnnnooopppqqqrrrssstttuuuvvvwwwxxxyyyzzz\
aaabbbcccdddeeefffggghhhiiijjjkkklllmmmnnnooopppqqqrrrssstttuuuvvvwwwxxxyyyzzz\
aaabbbcccdddeeefffggghhhiiijjjkkklllmmmnnnooopppqqqrrrssstttuuuvvvwwwxxxyyyzzz\
aaabbbcccdddeeefffggghhhiiijjjkkklllmmmnnnooopppqqqrrrssstttuuuvvvwwwxxxyyyzzz\
aaabbbcccdddeeefffggghhhiiijjjkkklllmmmnnnooopppqqqrrrssstttuuuvvvwwwxxxyyyzzz\
aaabbbcccdddeeefffggghhhiiijjjkkklllmmmnnnooopppqqqrrrssstttuuuvvvwwwxxxyyyzzz";
	printf("%sLE VRAI = %s\n",KBLU,    strdup(ddst4));


	printf("%s\n----------->>>chaine de 10<<<-----------\n\n", KYEL);
	char ddst5[] = "abcdefghijxxx";
	printf("%sLE MIEN = %s\n", KCYN, ft_strdup(ddst5));
	char ddst6[] = "abcdefghijxxx";
	printf("%sLE VRAI = %s\n",KBLU,    strdup(ddst6));


	printf("%s\n----------->>>chaine de 15<<<-----------\n\n", KYEL);
	char ddst7[] = "abcdefghijklmno";
	printf("%sLE MIEN = %s\n", KCYN, ft_strdup(ddst7));
	char ddst8[] = "abcdefghijklmno";
	printf("%sLE VRAI = %s\n",KBLU,    strdup(ddst8));
}
