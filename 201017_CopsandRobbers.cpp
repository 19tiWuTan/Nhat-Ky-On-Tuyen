/// task : cho ma trận gồm các kí tự thường , '.' và 1 kí tự 'B'
/// để đặt một hàng rào '#' vào kí tự c ( c = 'a'..'b') sẽ tốn cost(c)
/// tìm cách đặt các hàng rào để 'B' không đi ra được khỏi bảng 

/// -> MIN CUT
/// mỗi ô (x, y) ta sẽ tạo ra 2 đinh 
    /// (x, y)+ ra
    /// (x, y)- vào
/// (x,y)+ -> (u, v)- c = +oo hoặc c = cost(char(u, v))  (char(u,v) = 'a'..'z')
/// (x,y)- -> (x, y)+ c = +oo



#incldue <bits/stdc++.h>
int main(){

}
