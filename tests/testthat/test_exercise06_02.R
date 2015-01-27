library(HW6)

expect_equal(simplify2array(list(c(1,2,3), c(4,5,6))), matrix(c(1,2,3,4,5,6), ncol=2))
expect_equal(simplify2array(list(c(1,2,3,4,5,6))), c(1,2,3,4,5,6))
expect_equal(simplify2array(list(c(1,2,3), c(1,2,3,4))), list(c(1,2,3), c(1,2,3,4)))
expect_equal(simplify2array(list()), numeric(0))
expect_error(simplify2array(list(c(1,2,3), c("a", "b","c"))))

