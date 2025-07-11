#include <stddef.h>

#include "unity.h"
#include "libft.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>

void test_ft_atoi()
{

}

void test_ft_bzero()
{
	// simple test case for a few elements
	char buffer1[10];
	char buffer2[10];

	memset(buffer1, 'A', sizeof(buffer1));
	memset(buffer2, 'A', sizeof(buffer2));

	bzero(buffer1, 5);
	ft_bzero(buffer2, 5);

	TEST_ASSERT_EQUAL_MEMORY(buffer1, buffer1, sizeof(buffer1));

	// test case for each elements
	char buff1[6] = "hello";
	char buff2[6] = "hello";

	bzero(buff1, 6);
	ft_bzero(buff2, 6);
	TEST_ASSERT_EQUAL_MEMORY(buff1, buff2, 6);

	// zero lenght test
	char buffer11[5] = "abcd";
	char buffer21[5] = "abcd";

	bzero(buffer11, 0);
	ft_bzero(buffer21, 0);

	TEST_ASSERT_EQUAL_MEMORY(buffer1, buffer2, 5);
	
	// test null test case
	ft_bzero(NULL, 0);
	TEST_PASS();
}

void test_ft_isalnum()
{
	char isalphacapital = 'A';
	char isalpha = 'a';
	char num = '1';
	int i;

	while (isalphacapital <= 'Z')
	{
		i = isalnum(isalphacapital);
		//printf("isalnum(%c) = %d\n", isalphacapital, i);
		TEST_ASSERT_EQUAL_INT(!!i, !!ft_isalnum(isalphacapital));
		isalphacapital++;
	}
	while (isalpha <= 'z')
	{
		TEST_ASSERT_EQUAL_INT(!!isalnum(isalpha), !!ft_isalnum(isalpha));
		isalpha++;
	}
	while (num <= '9')
	{
		TEST_ASSERT_EQUAL_INT(!!isalnum(num), !!ft_isalnum(num));
		num++;
	}
}

void test_ft_isalpha()
{
	for (int c = 0; c <= 255; c++)
	{
		int expected = !!isalpha(c);
		int actual = ft_isalpha(c);
		TEST_ASSERT_EQUAL_INT(expected, actual);
	}
}

void test_ft_isascii()
{
	for (int i = 0; i <= 127; i++)
	{
		int expected = !!isascii(i);
		int actual = ft_isascii(i);
		TEST_ASSERT_EQUAL_INT(expected, actual);
	}
}

void	test_ft_isdigit()
{
}

void test_ft_isprint()
{
	for (int i = 40; i <= 176; i++)
	{
		int excpected = isprint(i);
		int actual = ft_isprint(i);
		//printf("i = %d char = %c,  isprint = %d ft_isprint = %d\n", i, i, excpected, actual); 

		TEST_ASSERT_EQUAL_INT(!!excpected, actual);
	}
}

void test_ft_memchr()
{

}

void test_ft_memcmp()
{

}

void test_ft_memcpy()
{

}

void test_ft_memmove()
{

}

void test_ft_memset()
{
	char str[50] = "GeeksForGeeks is for programming geeks.";
	TEST_ASSERT_EQUAL_STRING(memset(str + 13, '.', 8*sizeof(char)), ft_memset(str + 13, '.', 8*sizeof(char)));
}

void test_ft_strchr()
{

}

void	test_ft_strlcat()
{

}

void	test_ft_strlcpy()
{

}

void	test_ft_strlen()
{
	unsigned long long size = 5;
	TEST_ASSERT_EQUAL_UINT64(size, ft_strlen("abcdf"));
	TEST_ASSERT_EQUAL_UINT64(0, ft_strlen(""));
	TEST_ASSERT_EQUAL_UINT64(0, ft_strlen(NULL));
}

void	test_ft_strncmp()
{
	//compare same string, equal
	char s1[50] = "ab";
	char s2[50] = "ab";

	int excpected = strncmp(s1, s2, 6);
	int actual = ft_strncmp(s1, s2, 6);
	TEST_ASSERT_EQUAL_INT(excpected, actual);


	// P is lower than Z
	excpected = strncmp("AZP", "AZZ", 3);
	actual = ft_strncmp("AZP", "AZZ", 3);
	printf("excpected strn= %d, actual ft= %d\n", excpected, actual);
	TEST_ASSERT_LESS_OR_EQUAL(0, excpected);
	TEST_ASSERT_LESS_OR_EQUAL(0, actual);

	// equal a
	TEST_ASSERT_EQUAL_INT(strncmp("abc", "abc", 0), ft_strncmp("abc", "abc", 0));

	// greater 
	TEST_ASSERT_GREATER_OR_EQUAL(strncmp("abc", "", 3), ft_strncmp("abc", "", 3));
	TEST_ASSERT_GREATER_OR_EQUAL(strncmp("abc", "abd", 3), ft_strncmp("abc", "abd", 3));

}

void	test_ft_strnstr()
{

}

void test_ft_strrchr()
{

}

void test_ft_tolower()
{
	char i = 'A';
	while (i <= 'Z')
	{
		TEST_ASSERT_EQUAL(tolower(i), ft_tolower(i));
		i++;
	}
	TEST_ASSERT_EQUAL(tolower('A'), ft_tolower('A'));
	TEST_ASSERT_EQUAL(tolower('Z'), ft_tolower('Z'));
	TEST_ASSERT_EQUAL(tolower(' '), ft_tolower(' '));
	TEST_ASSERT_EQUAL(tolower('a'), ft_tolower('a'));
	TEST_ASSERT_EQUAL(tolower('0'), ft_tolower('0'));
}

void test_ft_toupper()
{
	char i = 'a';
	while (i <= 'z')
	{
		TEST_ASSERT_EQUAL(toupper(i), ft_toupper(i));
		i++;
	}
	TEST_ASSERT_EQUAL(toupper('A'), ft_toupper('A'));
	TEST_ASSERT_EQUAL(toupper('Z'), ft_toupper('Z'));
	TEST_ASSERT_EQUAL(toupper(' '), ft_toupper(' '));
	TEST_ASSERT_EQUAL(toupper('a'), ft_toupper('a'));
	TEST_ASSERT_EQUAL(toupper('0'), ft_toupper('0'));
}

void setUp()
{

}

void tearDown()
{

}

int main(void)
{
	UNITY_BEGIN();

	RUN_TEST(test_ft_atoi);
	RUN_TEST(test_ft_bzero);
	RUN_TEST(test_ft_isalnum);
	RUN_TEST(test_ft_isalpha);
	RUN_TEST(test_ft_isascii);
	RUN_TEST(test_ft_isdigit);
	RUN_TEST(test_ft_strchr);
	RUN_TEST(test_ft_strlcat);
	RUN_TEST(test_ft_strlcpy);
	RUN_TEST(test_ft_strlen);
	RUN_TEST(test_ft_strncmp);
	RUN_TEST(test_ft_strnstr);
	RUN_TEST(test_ft_strrchr);
	RUN_TEST(test_ft_tolower);
	RUN_TEST(test_ft_toupper);
	RUN_TEST(test_ft_isprint);
	UNITY_END();

	return 0;
}
