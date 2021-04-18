Build Boost
===========

[![Test](https://github.com/egor-tensin/build-boost/actions/workflows/test.yml/badge.svg)](https://github.com/egor-tensin/build-boost/actions/workflows/test.yml)

This GitHub action downloads & builds Boost libraries in your workflow run.

* Downloads a distribution of the specified Boost version and unpacks it.
* Builds the required libraries using the specified toolset.

Use it in your workflow like this:

    - name: Build Boost
      id: boost
      uses: egor-tensin/build-boost@v1
      with:
        version: 1.71.0
        libraries: filesystem program_options system
        platform: x64
        configuration: Release

    - name: Show paths
      run: |
        printf 'Boost has been unpacked to: %s\n' '${{ steps.boost.outputs.root }}'
        printf 'Libraries can be found here: %s\n' '${{ steps.boost.outputs.librarydir }}'
      shell: bash

* `x64` is the default value for the `platform` parameter and can be omitted.
Use `x86` if you want to build 32-bit binaries.
* `Release` is the default value for the `configuration` parameter and can be
omitted.
Use `Debug` if you want to build debug binaries.
* Set `static` to `1` if you want to build static libraries.
* Set `static-runtime` to `1` if you want to link to the static runtime.

API
---

| Input          | Value        | Default | Description
| -------------- | ------------ | ------- | -----------
| version        | **required** |         | Boost version to build, e.g. `1.71.0`.
| libraries      | **required** |         | Space-separated list of libraries to build, e.g. `filesystem program_options system`.
| toolset        | auto         | ✓       | Use GCC on Linux and MSVC on Windows.
|                | msvc         |         | Use MSVC.
|                | gcc          |         | Use GCC.
|                | mingw        |         | Use MinGW-w64.
|                | clang        |         | Use Clang.
| platform       | x64          | ✓       | Build 64-bit binaries.
|                | x86          |         | Build 32-bit binaries.
| configuration  | Release      | ✓       | Build Release binaries.
|                | Debug        |         | Build Debug binaries.
| static         | *any*        | ✓       | Shared libraries.
|                | 1            |         | Static libraries.
| static-runtime | *any*        | ✓       | Link to the shared runtime.
|                | 1            |         | Link to the static runtime.
| directory      | *empty*      | ✓       | Build in `${{ runner.workspace }}/boost`.
|                | *any*        |         | Build in a custom directory.

| Output     | Example                                | CMake input      | Description
| ---------- | -------------------------------------- | ---------------- | -----------
| root       | D:\a\project\boost                     | BOOST_ROOT       | Root Boost directory.
| librarydir | D:\a\project\boost\stage\x64\Debug\lib | BOOST_LIBRARYDIR | Directory that contains the built libraries.

Use the `librarydir` output to locate the built libraries.
You can pass it to CMake using the `BOOST_LIBRARYDIR` parameter:

    > cmake -D "BOOST_ROOT=${{ steps.boost.outputs.root }}" \
            -D "BOOST_LIBRARYDIR=${{ steps.boost.outputs.librarydir }}" \
            ...

Notes
-----

* This action uses my other project [cmake-common] to actually download and
build Boost.
* [cmake-common] sees *a lot* more testing than this action, while this action
delegates almost everything to it.
* You can use my other actions [setup-gcc], [setup-mingw], [setup-clang] to set
up different toolsets targetting both x86 and x64.

[cmake-common]: https://github.com/egor-tensin/cmake-common
[setup-gcc]: https://github.com/egor-tensin/setup-gcc
[setup-mingw]: https://github.com/egor-tensin/setup-mingw
[setup-clang]: https://github.com/egor-tensin/setup-clang

License
-------

Distributed under the MIT License.
See [LICENSE.txt] for details.

[LICENSE.txt]: LICENSE.txt
