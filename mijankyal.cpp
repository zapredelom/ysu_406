#include <iostream>
#include <cstring>
#include <type_traits>
#include "max.h"
#include "Matrix.h"
#include "Point.h"
#include "Employee.h"
#include <cmath>
const int c_rows = 5;
const int c_columns = 6;
const int square_dim = 2;

void two_pow_count(int mat[][c_columns], int rows, int ans[]) {
	int ind = 0;
	for (int i = 0; i < c_rows; ++i) {
		for (int j = 0; j < c_columns; ++j) {
			if (mat[i][j] > 0 && (mat[i][j] & (mat[i][j] - 1)) == 0) {
				ans[ind] = i;
				ind++;
				break;
			}
		}
	}

}

bool is_prime(int n) {
	int i = 2;
	while( i * i <= n){
		if (n % i == 0)
			return false;
		i++;
	}
	return true && n > 1;
}

bool row_prime_is_orderd(int row[], int size) {
	int first_prime = -1;
	for (int i = 0; i < size; i++) {
		if (is_prime(row[i])) {
			first_prime = i; 
			break;
		}
	}

	if (first_prime == -1)
		return true;
	for (int i = first_prime+1; i < size; i++) {
		if (is_prime(row[i])) {
			if (row[i] >= row[first_prime]) {
				return false;
			}
			else {
				first_prime = i;
			}
		}
	}
	return true;
}
void prime_is_ordered(int mat[][c_columns], int rows, bool ans[]) {
	for (int i = 0; i < rows; i++) {
		ans[i] = false;
	}
	for (int i = 0; i < rows; i++) {
		if (row_prime_is_orderd(mat[i], rows)) {
			ans[i] = true;
		}
		else {
			ans[i] = false;
		}
	}
}


void sort_mat_by(int mat[][c_columns], int rows) {
	for (int k = 0; k < rows; k++) {
		for (int i = 0; i < rows - 1; i++) {
			int first_sum = 0;
			int second_sum = 0;
			for (int j = 0; j < c_columns; j++) {
				first_sum += (mat[i][j] > 0 ? mat[i][j] : 0);
				second_sum += (mat[i + 1][j] > 0 ? mat[i + 1][j] : 0);
			}
			if (first_sum > second_sum) {
				for (int j = 0; j < c_columns; j++) {
					int tmp = mat[i][j];
					mat[i][j] = mat[i + 1][j];
					mat[i + 1][j] = tmp;
				}
			}
		}
	}
}

void swap(int mat[][c_columns], int i, int j) {

	for (int k = 0; k < c_columns; k++) {
		int tmp = mat[i][k];
		mat[i][k] = mat[j][k];
		mat[j][k] = tmp;
	}
}
bool has_equal_bits_on_ends(int n) {
	int sz = sizeof(int);
	int first_byte = n >> (sz-1) * 8;
	int last_byte = 0xFF & n;
	int first_set_count = 0;
	while (first_byte) {
		first_set_count += first_byte % 2;
		first_byte >>=1;
	}
	int last_set_count = 0;
	while (last_byte) {
		first_set_count += last_byte % 2;
		last_byte >>= 1;
	}

	return last_set_count == first_set_count;
}
bool first_last_bits_are_eqaul_count(int mat[][c_columns], int i, int j) {
	int first_row_count = 0;
	int second_row_count = 0;
	for (int k = 0; k < c_columns; k++) {
		if (has_equal_bits_on_ends(mat[i][k]))
		{
			first_row_count++;
		}
		if (has_equal_bits_on_ends(mat[j][k])) {
			second_row_count++;
		}
	}
	return first_row_count < second_row_count;
}
void sort_by_bit_equality(int mat[][c_columns], int rows) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < rows-1; j++) {
			if (first_last_bits_are_eqaul_count(mat, j, j + 1)) {
				swap(mat, j, j + 1);
			}
		}
	}
}

void equal_rows(int mat[][c_columns], int rows, bool ans[]) {
	for (int i = 1; i < rows; i++) {
		ans[i] = true;
		for (int j = 0; j < c_columns; j++) {
			if (mat[0][j] != mat[i][j])
			{
				ans[i] = false; 
				break;
			}
		}
	}
}


void mul(int a[][square_dim], int b[][square_dim], int result[][square_dim]) {
	for (int i = 0; i < square_dim; i++)
	{
		for (int j = 0; j < square_dim; j++) {
			result[i][j] = 0;
			for (int k = 0; k < square_dim; k++) {
				result[i][j] += a[i][k] * b[k][j];
			}
		}
	}
}

void pow(int a[][square_dim], int p) {
	int current[square_dim][square_dim] = {0};
	for (int i = 0; i < square_dim; i++) {
		current[i][i] = 1;
	}
	int result[square_dim][square_dim] = { 0 };
	for (int i = 0; i < p; i++) {
		mul(a, current, result);
		for (int j = 0; j < square_dim; j++) {
			for (int k = 0; k < square_dim; k++) {
				current[j][k] = result[j][k];
			}
		}
	}
	for (int i = 0; i < square_dim; i++) {
		for (int j = 0; j < square_dim; j++) {
			a[i][j] = current[i][j];
		}
	}
}
 
int SquareEvaluator( int (*fn)(int , int ) , int a, int b) {
	return fn(a * a, b * b);
}
int mul(int a, int b) {
	return a * b;
}
int square(int a) {
	return a * a;
}
int median_calculator(int (*fn)(int), int* arr, int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += fn(arr[i]);
	}
	return sum / size;
}
double integral(double (*fn)(double), double a, double b, int n)
{
	    
}

void to_upper(char* a, int size) {
	for (int i = 0; i < size; i++) {
		if (a[i] >= 'a' && a[i] <= 'z')
		{
			a[i] += 'A' - 'a';
		}
	}
}
void is_alphabetical(const char* a) {

	int i = 0;
	while (a[i+1] != '\0') {
		if (a[i] > a[i+1])
		{
			std::cout << "NO";
			return;
		}
		i++;
	}
	std::cout << "YES";
}
int hex_pow(int n, int p) {
	int ret = 1;
	while (p) {
		ret *= 16;
		p--;
	}
	return ret* n;
}
int get_hex_digit(char c) {
	int digit = 0;
	if (c >= '0' && c <= '9')
	{
		digit = c - '0';
	}
	else if (c>='A' && c <='F') {
		digit = c - 'A' + 10;
	}
	else {
		digit = c - 'a' + 10;
	}
	return digit;
}
int hex_to_dec(const char* str) {
	int len = strlen(str);
	int ret = 0;
	int i = 0;
	while (len > 0) {
		int digit = get_hex_digit(str[len-1]);
		ret += hex_pow(digit, i);
		len--;
		i++;
	}
	return ret;

}
bool is_letter(char c) {
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}
bool is_digit(char c) {
	return c >= '0' && c <= '9';
}
bool is_alphanumberic(char c) {
	return is_digit(c) || is_letter(c);
}
bool is_identificator(const char* str) {
	if (str == NULL)
		return false;
	if (str[0] != '_' && !is_letter(str[0]))
		return false;
	str++;
	while (*str != '\0') {
		if (*str != '_' && !is_alphanumberic(*str))
			return false;
		str++;
	}
	return true;
}
bool is_polindrom(const char* str) {
	const char* start = str;
	const char* end = str + strlen(str) -1;
	while (start != end) {
		while (!is_letter(*start) && start != end) start++;
		while (!is_letter(*end) && start != end) end--;
		if (*end != *start) {
			return false;
		}
		if (start == end || end - start == 1)
			return true;
		start++;
		end--;
	}
}

int get_max_row_number(double** arr, int n, int m) {
	double max = arr[0][0];
	int row_num = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (max < arr[i][j]) {
				max = arr[i][j];
				row_num = i;
			}
		}
	}
	return row_num;
}

void problem_1() {
	int n, m;
	std::cin >> n >> m;
	double** arr = new double* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new double[m];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> arr[i][j];
		}
	}
	int row_num = get_max_row_number(arr, n, m);
	double** arr2 = new double* [n - 1];
	for (int i = 0; i < n - 1; i++) {
		arr2[i] = new double[m];
	}

	for (int i = 0, initial_row = 0; i < n - 1; i++, initial_row++) {
		for (int j = 0; j < m; j++)
		{
			if (i == row_num) {
				initial_row++;
			}
			arr2[i][j] = arr[initial_row][j];
		}
	}
	for (int i = 0; i < n - 1; i++) {
		delete[] arr[i];
		delete[] arr2[i];
	}
	delete[] arr[n - 1];
	delete[] arr;
	delete[] arr2;

}
void transform_line_to_upper(char* line) {
	int i = 0;
	while (line[i] != '\0') {
		if (line[i] >= 'a' && line[i] <= 'z') {
			line[i] = line[i] - ('a' - 'A');
		}
		i++;
	}

	while (*line != '\0') {
		if (*line >= 'a' && *line <= 'z') {
			*line = *line - ('a' - 'A');
		}
		line++;
	}
}
void problem_2() {
	char line[81];
	std::cin >> line;
	transform_line_to_upper(line);
	std::cout << line;
}
int main() {
	/*int d_rows;
	int d_columns;
	std::cin >> d_rows >> d_columns;
	int** d_mat = new int*[d_rows];
	for (int i = 0; i < d_rows; i++)
	{
		d_mat[i] = new int[d_columns];
	}
	for (int i = 0; i < d_rows * d_columns; i++) {
		int column = i / d_rows;
		int row = (column % 2 == 0) ? i % d_rows : d_rows - i % d_rows - 1;
		d_mat[row][column] = i + 1;
	}

	for (int i = 0; i < d_rows; i++) {
		for (int j = 0; j < d_columns; j++) {
			std::cout << d_mat[i][j]<< " ";
		}
		std::cout << std::endl;
	}

	for (int i = 0; i < d_rows; i++)
	{
		delete[] d_mat[i];
	}
	delete[] d_mat;*/    
	//char line[] = "the quick brown fox jumpes over the lazy dog";
	//for (int i = 0; i < strlen(line); i++) {
	//	if ((line[i] >= 'a' && line[i] <='z')) {
	//		std::cout << char(line[i] + ('A' - 'a')) ;
	//	}
	//	else {
	//		std::cout << line[i];
	//	}
	//}
	//std::cout << Sum("abc", "def"); // abcdef
	//std::cout << SquareEvaluator(non_template_sum, 5, 2);
	//std::cout << SquareEvaluator(mul, 5, 2);
	//float arr[] = { 1,2,3,4,5,6};
	//Matrix m(5, 6);
	//std::cout << m._rows;
	//m.print();
	//m.set(0, 0, 1.);
	//std::cout << "-------------------------\n";
	//m.print();
	//m.add_row(arr, 6);
	//std::cout << "-------------------------\n";
	//m.print();
	//float column[] = { -1,-2,-3,-4,-5 };
	//m.add_column(column, 5);
	//
	//std::cout << m.get(0, 0) << std::endl;
	//char input[7];
	//std::cin.getline(input, 7);
	//std::cin >> input;
	//std::cout << input << std::endl;
	Employee e("John", "CEO", 10000);
	e.set_day(10);
	std::cout << e.get_name();
	Employee* employes = new Employee[2];
	employes[0].get_name();


	delete[] employes;
	
}
