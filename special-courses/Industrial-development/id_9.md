# Industrial Development 9
## Cmake 2/2

###Config files v. find files

`> cmake -DCMAKE_INSTALL_PREFIX=_install`
`> cmake --build _builds`
`> cmake --build _builds --target install`

`Config` files stores kv target - path (*configs can differentiate between release and debug version*)
`Findfiles` (*findfiles cant differentiate between release and debug version*)

### Package

`> cmake --build _builds --target package`

VERSION TWEAK -- package change (readme change or email change)
VERSION PATCH -- no interface change, code imp change
VERSION MINOR -- interface change with backwards-compatibility
VERSION MAJOR -- incompatible changes

[Source:](https://semver.org)
~~~
Given a version number MAJOR.MINOR.PATCH, increment the:

MAJOR version when you make incompatible API changes,
MINOR version when you add functionality in a backwards-compatible manner, and
PATCH version when you make backwards-compatible bug fixes.
Additional labels for pre-release and build metadata are available as extensions to the MAJOR.MINOR.PATCH format.
~~~

`> cpack -G DEB`
