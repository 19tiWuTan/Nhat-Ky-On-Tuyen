/*
  Có n người tham gia cuộc thi, nguyên tắc xếp hạng là ai cao điểm hơn thì rank của người đó sẽ có giá trị thấp hơn, 
  bằng điểm thì rank bằng nhau, rank=1 tức là người đó đang ở vị trí dẫn đầu.


Ví dụ: n=6 và điểm số của mỗi người thi là 5,3,4,3,4,5 thì sẽ tương ứng rank là 1,5,3,5,3,1.

Ban đầu tất cả điểm số của mỗi người là 0. 
Có w ngày thi, mỗi ngày thì sẽ có một số người được tăng điểm số lên 1, sau mỗi ngày thì bảng xếp hạng về rank sẽ có thể thay đổi.

Yêu cầu: Hỏi rank trung bình của mỗi người là bao nhiêu.
input : 
3 2
2 1 2
2 1 3

output : 
1.0000000000
1.5000000000
2.5000000000

  
  
  
  xét người p, những ngày xuất hiện d1 < d2 < ... < dk ( Những ngày dược cộng điểm ) 
  
  thì p sẽ có điểm = 0 từ ngày 0 -> d1 - 1
  có điểm = 1 từ ngày d1 -> d2 - 1
  and so on...
  
  rank = số thằng có số điểm lớn hon + 1
  
  vector < {Tl, Tr, p} > adj[point]  ( point = w -> 0 )
  sum[p] = sum(a[L->R])
  duyệt từng [Tl, Tr, p] : adj[point] 
  update a[i] += 1 ( với mọi i thuộc [L,R] )
  
  
*/
