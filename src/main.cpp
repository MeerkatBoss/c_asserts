#include "meerkat_assert/asserts.h"

#include <stdio.h>

int main()
{
    SAFE_BLOCK_START
    {
        int x = 0, y = 0;
        ASSERT_EQUAL(scanf("%d %d", &x, &y), 2);

        ASSERT_POSITIVE(printf("%d\n", x + y));
    }
    SAFE_BLOCK_HANDLE_ERRORS
    {
        printf("Assertion failed in file '%s:%zu' (%s).\n"
                "Expectation '%s' not met with expression '%s'",
                assertion_info.filename,
                assertion_info.line_number,
                assertion_info.function,
                assertion_info.expectation,
                assertion_info.expression);
        return 1;
    }
    SAFE_BLOCK_END

    return 0;
}
