#include <stdbool.h>
#include "list.h"
#include <stdio.h>
#include "tests.h"


int main(void) {
	if (!testForSetValue() || !testForCreateList() || !testForAdd() || !testForGetValueForNormalValue() || !testForGetValueForNullValue() || !testForRemoveForNormalValue()) {
		printf("tests are not completed");
		return -1;
	}
	return 0;
}