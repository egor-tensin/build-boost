v2
--

* Boost is no longer simply built using `b2 stage`; instead, it is installed
  using `b2 install`.
    * The `librarydir` output was removed.
    * The new output `install_dir` contains a full installation of Boost,
      including the headers and built libraries.
    * You should now pass `install_dir` as the `BOOST_ROOT` parameter value to
      CMake. `BOOST_LIBRARYDIR` is no longer required.
    * The `root` output (pointing to the unpacked archive directory) is
      deprecated.

v1
--

* Initial release.
