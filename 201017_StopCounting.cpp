/// task : tìm cách xóa 1 đoạn liên tiếp duy nhất sao cho những phần tử còn lại có trung bình cộng là lớn nhất
/// chặt nhị phân số thực X
/// khi chặt X để xét xem X có phải là kết quả hay không, lấy a[i]-=X ( với mọi i)
/// pre[i] = sum(a[1] + a[2] + .. a[i])
/// suf[i] = sum(a[n] + a[n-1] + .. + a[i])

/// X thỏa khi tồn tại (i , j) : 1 <= i <= j <= n và pre[i] + suf[j] >= 0
/// mx_pre[i] = max(pre[1], pre[2], .. pre[i])
/// mx_suf[i] = max(suf[n], suf[n-1], .. suf[i])

/// bài toán quy về tìm vị trí i : mx_pre[i] + mx_suf[i+1] >= 0
