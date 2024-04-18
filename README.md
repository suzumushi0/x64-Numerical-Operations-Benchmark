# x64 Numerical Operations Benchmark

2024/4/19 に開催された C++ MIX #10 の「x64 のスカラー，SIMD 演算性能を測ってみた」で使用したソースコードです．ご自由にお使いください．

https://cppmix.connpass.com/event/311283/

ファイルの内容は以下の通りです．

`float-scalar-noopt.cpp     `
浮動小数点，スカラー，ループ展開なし

`float-scalar-opt.cpp       `
浮動小数点，スカラー，ループ展開

`float-vector-loop.cpp      `
浮動小数点，ベクトル，自動ベクトル化

`float-vector-valarray.cpp  `
浮動小数点，ベクトル，valarray

`int-scalar-noopt.cpp       `
整数，スカラー，ループ展開なし

`int-scalar-opt.cpp         `
整数，スカラー，ループ展開

`int-vector-loop.cpp        `
整数，ベクトル，自動ベクトル化

`int-vector-valarray.cpp    `
整数，ベクトル，valarray

`math-scalar-noopt.cpp      `
初等関数 (スカラー，ループ展開なし)

