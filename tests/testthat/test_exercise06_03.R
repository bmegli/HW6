library(HW6)

expect_true(class(perms(0))=="matrix", mode(perms(0))=="integer", ncol(perms(0))==0)
expect_equal(perms(2), matrix(c(1,2,2,1), nrow=2))
expect_equal(perms(3), matrix(c(1,2,3,1,3,2,2,1,3,2,3,1,3,1,2,3,2,1), byrow=TRUE, ncol=3))
expect_error(perms(-1))
expect_error(perms(157))

