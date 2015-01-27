library(HW6)

expect_equal(mode(c(1, 2, 3, 1)), 1)
expect_equal(mode(c(NA)), integer(0))
expect_equal(mode(NA), integer(0))
expect_true(mode(c(1, 2, 1 , 1, 3)) %in% c(1,2))
