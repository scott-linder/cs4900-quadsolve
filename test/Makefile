TESTS = test_nan_input test_no_roots test_single_root test_two_real_roots

.PHONY: test
test: ${TESTS}
	for test in ${TESTS}; do echo $$test; ./$$test; done
