### S(uckless)CON(cord)C(lient)

### Usage
Either use as a base for your own client (include hdr.hpp), or use it vanilla (build main.cpp)

### Basic Principles
Similar to how OC core stores the graphs in your filesystem, SCONC is derived from the suckless priniciple and similar in intention to the IRC client [ii](https://tools.suckless.org/ii/). Monitor the `home_dir` provided to `iopress` in it\'s contruction for updates; sub directories are created for graphs and their respective containers. SCONC has no knowledge of any of the container\'s inherited protocols; it\'s reccomened to extend SCONC if you're using a complex protocol.
