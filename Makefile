.PHONY: deploy
deploy:
	cd src; make; cp quadmain ../quadsolve

.PHONY: clean
clean:
	cd src; make clean

# all tests
.PHONY: test
test: deploy utest ftest

# unit tests
.PHONY: utest
utest:
	cd src; make test

# functional tests
.PHONY: ftest
ftest:
	cd test; make test
