SODA
===

## Overview

This is the secure version of `Native Spark`, or `Vega`(https://github.com/rajasekarv/vega). It is in development now.

## Setup Environment

### git procedure

```
git clone https://github.com/SODA-REPO/SODA.git
git submodule update --init --recursive
```

### Install rust toolchain in the master node

Please refer to https://www.rust-lang.org/tools/install. It's recommended to use `rustup` for management. 

### Install Intel SGX toolchain

We require Intel SGX SDK 2.14.

Tasks will not run on the master node, and all the tasks run on slave nodes. So, SGX toolchain (Driver, PSW, SDK) needs to be installed on slave nodes, while SDK needs to be installed on the master node for compiling the code. All are installed in `/opt/intel/`.

### Config for Spark

Please refer to https://rajasekarv.github.io/vega/ for `Getting started` part and `Executing an application` part. For setting environment variables, here are two examples in `./bin`. To make the configuration effective, you need to type, e.g., `source bin/set_env_local.sh`. `bin/set_env_local.sh` is useless.

