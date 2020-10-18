/*
 Cho n thành phố, mỗi thành phố đều sẽ có một giá trị ở mỗi ngày trong tuần, 1 tuần sẽ có 7 ngày. Cụ thể, ở thành phố i thì:

ngày thứ 2 sẽ mang giá trị là vi
ngày thứ 3 sẽ mang giá trị là vi+d
ngày thứ 4 sẽ mang giá trị là vi+2d
ngày thứ 5 sẽ mang giá trị là vi+3d
ngày thứ 6 sẽ mang giá trị là vi+2d
ngày thứ 7 sẽ mang giá trị là vi+d
ngày chủ nhật sẽ mang giá trị là vi
Cho q truy vấn, mỗi truy vấn sẽ gồm 2 giá trị s t. 
Anh T xuất phát từ thành phố s và di chuyển đến thành phố t theo 2 hướng trái phải, cụ thể

Nếu s<t thì di chuyển s,s+1,s+2,...,t
Nếu s>t thì di chuyển s,s−1,s−2,...,t
Ngày xuất phát ở đỉnh s là ngày thứ 2, cứ sang đỉnh tiếp theo thì sẽ sang ngày mới, cụ thể 2,3,4,5,6,7, chủ nhật, 2.... 
Tại thành phố u ở ngày d thì anh ấy có thể làm 1 trong 2 thao tác:
Mua một sản phẩm ở thành phố u tốn giá trị mà thành phố u đang mang ở ngày d
Bán một sản phẩm ở thành phố u được giá trị mà thành phố u đang mang ở ngày d. 
Anh ấy chỉ bán được khi mà anh ấy đã mua một sản phẩm trước đó.
Sau khi bán xong thì ngay lập tức anh ấy không thể mua hoặc bán thêm 1 lần nào nữa, nghĩa là số lần mua và số lần bán là một là chỉ một.
Anh T có thể mua và bán ngay tại thành phố u.
Yêu cầu: Hỏi giá trị lớn nhất mà anh T có thể có khi di chuyển từ thành phố s sang thành phố t là gì.


quy bài toán về Cho L, R tìm max(Aj - Ai) (L <= i <= j <= R) ( với S < T)
                             max(Ai - Aj ) (với S > T)
                             

*/
