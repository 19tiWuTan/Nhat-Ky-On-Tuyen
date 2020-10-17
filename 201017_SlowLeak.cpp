///Cho đồ thị vô hướng đơn giản có trọng số n đỉnh m cạnh và số nguyên dương D, có t đỉnh được gọi là đặc biệt, mỗi cạnh nối từ đỉnh u sang đỉnh v có độ dài là w km
///Bạn xuất phát ở thành phố 1 và muốn đi đường đi ngắn nhất đến đỉnh n. Xe bạn có dung tích tối đa là D và ban đầu, 
///bạn có lượng xăng là D, khi đi 1 km bạn sẽ tốn 1 lít xăng. Nếu đang đi mà hết xăng (tức lượng xăng hiện tại về 0) thì bạn sẽ dừng mãi mãi,
///không thể đi được đến n. May thay có t đỉnh đặc biệt, nếu như bạn đang ở một đỉnh đặc biệt thì bạn có thể đổ đầy bình xăng (không kể lượng xăng hiện tại của bạn là bao nhiêu).

///Yêu cầu: Hỏi số km nhỏ nhất mà bạn có thể đi được từ thành phố 1 đến thành phố n là bao nhiêu.

/// floyd : tạo f[i][j] là đường đi ngắn nhất từ i -> j

/// dựng đồ thị mới gồm t + 2 đỉnh : 1, p[1], p[2], .., p[t], n, với các cạnh = (f[i][j] <= d ? f[i][j] : +oo) ( i = p[], j = p[] )
/// floyd để tìm đường đi ngắn nhất trên đồ thị mới này
