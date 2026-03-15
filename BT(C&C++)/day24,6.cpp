#include <iostream>
#include <cstring>
using namespace std;
int main(){
// Liệt kế hết tất cả các lệnh và giải thích ý nghĩa từng lệnh
//có trong #include <cstring>
    // memset: thiết lập giá trị cho một vùng nhớ
    // memcpy: sao chép một vùng nhớ
    // memcmp: so sánh hai vùng nhớ
    // strlen: trả về độ dài của chuỗi
    // strcpy_s: sao chép chuỗi
    // strncpy_s: sao chép n ký tự của chuỗi
    // strcat_s: nối chuỗi
    // strncat_s: nối n ký tự của chuỗi
    // strcmp: so sánh hai chuỗi
    // strncmp: so sánh n ký tự của hai chuỗi
    // strchr: tìm ký tự trong chuỗi
    // strstr: tìm chuỗi con trong chuỗi
    // strrchr: tìm ký tự trong chuỗi (từ phải sang trái)
    // strspn: tìm độ dài của phần đầu chuỗi khớp với một tập hợp các ký tự cho trước
    // strcspn: tìm độ dài của phần đầu chuỗi không khớp với một tập hợp các ký tự cho trước

    //Viết tất cả kí tự trong bảng ASII
    for(int i=33;i<127;i++){
        cout<<"Kí tự trong bảng ASII ô "<<i<<" là:"<<char(i)<<endl;
    }
    /*
Kí tự trong bảng ASII ô 33 là:!
Kí tự trong bảng ASII ô 34 là:"
Kí tự trong bảng ASII ô 35 là:#
Kí tự trong bảng ASII ô 36 là:$
Kí tự trong bảng ASII ô 37 là:%
Kí tự trong bảng ASII ô 38 là:&
Kí tự trong bảng ASII ô 39 là:'
Kí tự trong bảng ASII ô 40 là:(
Kí tự trong bảng ASII ô 41 là:)
Kí tự trong bảng ASII ô 42 là:*
Kí tự trong bảng ASII ô 43 là:+
Kí tự trong bảng ASII ô 44 là:,
Kí tự trong bảng ASII ô 45 là:-
Kí tự trong bảng ASII ô 46 là:.
Kí tự trong bảng ASII ô 47 là:/
Kí tự trong bảng ASII ô 48 là:0
Kí tự trong bảng ASII ô 49 là:1
Kí tự trong bảng ASII ô 50 là:2
Kí tự trong bảng ASII ô 51 là:3
Kí tự trong bảng ASII ô 52 là:4
Kí tự trong bảng ASII ô 53 là:5
Kí tự trong bảng ASII ô 54 là:6
Kí tự trong bảng ASII ô 55 là:7
Kí tự trong bảng ASII ô 56 là:8
Kí tự trong bảng ASII ô 57 là:9
Kí tự trong bảng ASII ô 58 là::
Kí tự trong bảng ASII ô 59 là:;
Kí tự trong bảng ASII ô 60 là:<
Kí tự trong bảng ASII ô 61 là:=
Kí tự trong bảng ASII ô 62 là:>
Kí tự trong bảng ASII ô 63 là:?
Kí tự trong bảng ASII ô 64 là:@
Kí tự trong bảng ASII ô 65 là:A
Kí tự trong bảng ASII ô 66 là:B
Kí tự trong bảng ASII ô 67 là:C
Kí tự trong bảng ASII ô 68 là:D
Kí tự trong bảng ASII ô 69 là:E
Kí tự trong bảng ASII ô 70 là:F
Kí tự trong bảng ASII ô 71 là:G
Kí tự trong bảng ASII ô 72 là:H
Kí tự trong bảng ASII ô 73 là:I
Kí tự trong bảng ASII ô 74 là:J
Kí tự trong bảng ASII ô 75 là:K
Kí tự trong bảng ASII ô 76 là:L
Kí tự trong bảng ASII ô 77 là:M
Kí tự trong bảng ASII ô 78 là:N
Kí tự trong bảng ASII ô 79 là:O
Kí tự trong bảng ASII ô 80 là:P
Kí tự trong bảng ASII ô 81 là:Q
Kí tự trong bảng ASII ô 82 là:R
Kí tự trong bảng ASII ô 83 là:S
Kí tự trong bảng ASII ô 84 là:T
Kí tự trong bảng ASII ô 85 là:U
Kí tự trong bảng ASII ô 86 là:V
Kí tự trong bảng ASII ô 87 là:W
Kí tự trong bảng ASII ô 88 là:X
Kí tự trong bảng ASII ô 89 là:Y
Kí tự trong bảng ASII ô 90 là:Z
Kí tự trong bảng ASII ô 91 là:[
Kí tự trong bảng ASII ô 92 là:\
Kí tự trong bảng ASII ô 93 là:]
Kí tự trong bảng ASII ô 94 là:^
Kí tự trong bảng ASII ô 95 là:_
Kí tự trong bảng ASII ô 96 là:`
Kí tự trong bảng ASII ô 97 là:a
Kí tự trong bảng ASII ô 98 là:b
Kí tự trong bảng ASII ô 99 là:c
Kí tự trong bảng ASII ô 100 là:d
Kí tự trong bảng ASII ô 101 là:e
Kí tự trong bảng ASII ô 102 là:f
Kí tự trong bảng ASII ô 103 là:g
Kí tự trong bảng ASII ô 104 là:h
Kí tự trong bảng ASII ô 105 là:i
Kí tự trong bảng ASII ô 106 là:j
Kí tự trong bảng ASII ô 107 là:k
Kí tự trong bảng ASII ô 108 là:l
Kí tự trong bảng ASII ô 109 là:m
Kí tự trong bảng ASII ô 110 là:n
Kí tự trong bảng ASII ô 111 là:o
Kí tự trong bảng ASII ô 112 là:p
Kí tự trong bảng ASII ô 113 là:q
Kí tự trong bảng ASII ô 114 là:r
Kí tự trong bảng ASII ô 115 là:s
Kí tự trong bảng ASII ô 116 là:t
Kí tự trong bảng ASII ô 117 là:u
Kí tự trong bảng ASII ô 118 là:v
Kí tự trong bảng ASII ô 119 là:w
Kí tự trong bảng ASII ô 120 là:x
Kí tự trong bảng ASII ô 121 là:y
Kí tự trong bảng ASII ô 122 là:z
Kí tự trong bảng ASII ô 123 là:{
Kí tự trong bảng ASII ô 124 là:|
Kí tự trong bảng ASII ô 125 là:}
Kí tự trong bảng ASII ô 126 là:~
    */
}