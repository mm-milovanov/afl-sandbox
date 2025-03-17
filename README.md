# AFL sandbox

## Download

``` sh
git clone git@git.navigator.local:mmilovanov/afl-sandbox
git submodule init
git submodule update
```

## Make AFL

``` sh
cd ./ext/AFL
make
```

## Proj make tasks

``` sh
make clean      # Remove build dir
make clean-test # Remove out test dir
make clean-all  # Remove build and out test dir
make            # Make prog
make test       # Test prog
```