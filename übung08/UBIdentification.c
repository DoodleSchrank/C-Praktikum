#include <stdio.h>
#include <string.h>

double convertTemperature(double* fahrenheit) {
	// wenn (fahrenheit == NULL) => UB! (1)
	double celsius = (*fahrenheit - 32)/1.8;
}

char* formatTemperature(double value, const char* unit) {
	char result[10];
	// ergebnis länger als 10 Zeichen => UB! (2)
	sprintf(result, "%f degree %s", value, unit);
	// gibt adresse lokaler variable, also einen ungültigen pointer zurück => UB! (3)
	return result;
}

int main() {
	// malloc nur implizit definiert da stdlib fehlt 0 => UB! (4)
	void* buffer = (void*)malloc(33);
	// länger als 32 Zeichen, dadurch ist buffer nicht null-byte terminiert
	strncpy(buffer, "enter a temperature in degree F: ", 33);
	// buffer ist nicht null-byte terminiert => UB! (5)
	printf("%s", buffer);

	scanf("%f", buffer);
	double celsius = convertTemperature(buffer);
	// hier wird auf den ungültigen pointer zugegriffen => UB! (6)
	printf("the temperatures is %s\n", formatTemperature(celsius, "C"));
}
