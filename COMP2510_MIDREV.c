

#include <stdio.h>
#include <ctype.h>

size_t find_first(const char s[], int c);
void replace_first(int a[], size_t n, int oldint, int newint);
void replace_last(char s[], int oldc, int newc);
size_t count(const int a[], size_t n, int x);
size_t count_alpha(const char s[]);
int all_digits(const char s[]);
void lowercase_copy(char dest[], const char src[]);
void reverse_copy(char dest[], const char src[]);
void ltrim_copy(char dest[], const char src[]);
int is_valid_id(const char s[]);

int main()
{
	char s[5] = "hello";
	

	printf("%d", find_first(s, 'e'));

	replace_first(s, 5, 'l', 'v');


	getchar();
	return 0;
}


/*
return the index of the first occurance of the character c in the string s.
If c is not found, return -1 (cast as size_t)
*/
size_t find_first(const char s[], int c) {
	size_t i;
	for (i = 0; s[i] != '\0'; i++)
		if (s[i] == c)
			return i;
	return (size_t)-1;
}

/*
replace the first occurance of the integer oldint with the integer new int.
*/
void replace_first(int a[], size_t n, int oldint, int newint) {;
	size_t i;
	for (i = 0; i < n; i++)
		if (a[i] == oldint)
			a[i] = newint;
}

/*
replaces the last occurance of the character oldc in the string s
with new c.
*/
void replace_last(char s[], int oldc, int newc) {
	size_t i, last = -1;
	for (i = 0; s[i] != '\0'; i++)
		if (s[i] == oldc)
			last = i;
	if (last != (size_t)-1)
		s[last] = newc;
}


/*
that returns the number of occurances of integer x in the array of n integers.
*/
size_t count(const int a[], size_t n, int x) {
	size_t i, count = 0;
	for (i = 0; i < n; i++)
		if (a[i] == x)
			count++;
	return count;
}

/*
returns the number of aplhabets in string s.
*/
size_t count_alpha(const char s[]) {
	size_t i, count = 0;
	for (i = 0; s[i] != '\0'; i++)
		if (isalpha(s[i]))
			count++;
	return count;
}


/*
returns 1 id string s consists entirely of digits, otherwise return 0;
*/
int all_digits(const char s[]) {
	size_t i;
	for (i = 0; s[i] != '\0'; i++)
		if (!isdigit(s[i]))
			return 0;
	return 1;
}

/*
copies the string src to dest with all uppercase characters changed
to lower case in the copy. Asume that dest is large enough to store the copy.
*/
void lowercase_copy(char dest[], const char src[]) {
	size_t i;
	for (i = 0; src[i] != '\0'; i++)
		dest[i] = toupper(src[i]);
	dest[i] = '\0';
}

/*
copies the string src to dest in reverse.
*/
void reverse_copy(char dest[], const char src[]) {
	size_t i, src_size = strlen(src);
	for (i = src_size; i > 0; i--)
		dest[src_size - i] = src[i - 1];
	dest[src_size] = '\0';
}


/*
makes a copy of src with leading whitespace removed and store in the copy of dest.
whitespace is any character that test true by the isspace function. assume that dest 
is large enough to store the copy.
*/
void ltrim_copy(char dest[], const char src[]) {
	size_t i, index = 0;
	for (i = 0; src[i] != '\0'; i++) 
		if (!isspace(src[i])) 
			dest[index++] = src[i];
	dest[index] = '\0';
}


/*
Tests wether string s is a valid bcit student id. For simplicity a valid student id 
is a string that starts with an 'a', or 'A' and is then followed y exactly 8 digits.
Return 1 for valid, 0 for invalid.
*/
int is_valid_id(const char s[]) {
	size_t i;

	if (strlen(s) != 9)
		return 0;

	if (toupper(s[0]) != 'A')
		return 0;

	for (i = 1; s[i] != '\0'; i++) 
		if (!isdigit(s[i]))
			return 0;

	return 1;
}






