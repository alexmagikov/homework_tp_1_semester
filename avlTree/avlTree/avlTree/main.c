#include "dictionary.h"
#include <stdlib.h>

int main() {
    Dictionary* dictionary = NULL;
    insert(&dictionary, "2", "value2");
    insert(&dictionary, "1", "value1");
    insert(&dictionary, "5", "value2");
    insert(&dictionary, "6", "value3");
    insert(&dictionary, "8", "value3");
    return 0;
}