# Chương trình quản lý thư viện trên console

Dự án cung cấp một chương trình C thuần (không dùng C++) phục vụ môn *Nhập môn lập trình*. Ứng dụng chạy trên console, không lưu xuống tệp và thực hiện toàn bộ thao tác quản lý độc giả, đầu sách, phiếu mượn – trả trong bộ nhớ.

## Đặc điểm kỹ thuật

- **Ngôn ngữ:** C thuần, biên dịch bằng `gcc`.
- **Không dùng cấu trúc (`struct`)** – toàn bộ dữ liệu được lưu trong các mảng một chiều và biến cơ bản.
- **Không dùng thư viện ngày giờ** (`<time.h>` / `<ctime>`). Khi cần xử lý ngày tháng, chương trình yêu cầu người dùng nhập chuỗi `dd/mm/yyyy`, tự tách và quy đổi theo giả định mỗi tháng 30 ngày.
- **Không đọc/ghi file.** Dữ liệu tồn tại tạm thời trong RAM cho tới khi thoát chương trình.
- **Không giới hạn số bản ghi**: khai báo hằng `MAX_*` lớn để người dùng nhập tùy ý.
- **Màn hình console tiếng Việt**, có căn lề bảng bằng `printf` với độ rộng cột cố định.

## Chức năng chính (menu 1–5)

1. **Quản lý độc giả**  
   - Xem danh sách độc giả, hiển thị đầy đủ thông tin và ngày tháng ở định dạng `dd/mm/yyyy`.  
   - Thêm độc giả mới, tự động tính ngày hết hạn thẻ sau 48 tháng.  
   - Cập nhật, xóa hoặc tìm độc giả theo CMND/họ tên.
2. **Quản lý sách**  
   - Xem danh sách đầu sách cùng số lượng, thể loại và tình trạng còn/đã mượn.  
   - Thêm, sửa, xóa đầu sách; tìm kiếm theo ISBN hoặc tên.  
   - Cập nhật tổng số lượng sẽ tự bảo toàn số bản đang được mượn.
3. **Lập phiếu mượn**  
   - Nhập CMND độc giả và danh sách ISBN.  
   - Ngày mượn/ trả dự kiến (7 ngày) nhập thủ công rồi quy đổi theo giả định 30 ngày/tháng.  
   - Tự giảm số lượng sách còn sẵn.
4. **Lập phiếu trả**  
   - Nhập ngày trả thực tế, lựa chọn trả thường hoặc báo mất từng cuốn.  
   - Tính tiền phạt: 5 000 đ/ngày trễ và 200 % giá sách nếu mất; vẫn cộng phạt trễ khi mất.  
   - Hoàn trả số lượng sách chưa mất.
5. **Thống kê**  
   - Tổng số đầu sách, thống kê theo thể loại.  
   - Tổng số độc giả, thống kê giới tính (không phân biệt hoa/thường).  
   - Số sách đang được mượn.  
   - Danh sách độc giả trả trễ (yêu cầu nhập ngày hiện tại để so sánh).

## Tổ chức mã nguồn

```
src/
├── main.c             – menu chính (1–5) và điều hướng chức năng
├── utils.{c,h}        – nhập liệu, xử lý ngày tháng, tiện ích chung
├── book*.{c,h}        – quản lý đầu sách, dữ liệu sách
├── reader*.{c,h}      – quản lý độc giả, dữ liệu độc giả
├── loan*.{c,h}        – phiếu mượn/trả và thống kê liên quan
└── stats.{c,h}        – các báo cáo thống kê
```

Dữ liệu được khai báo ở các tệp `*.data.c`, mỗi trường là một mảng 1 chiều. Các hàm `*_at(index)` trả về con trỏ tới ô bắt đầu của bản ghi, giúp thao tác như chuỗi con nhưng vẫn tuân thủ ràng buộc “mảng một chiều”.

## Biên dịch & chạy thử

```bash
gcc -Wall -Wextra -std=c11 src/*.c -o library
./library
```

Các script `build-and-run.sh` hoặc `Makefile` (nếu cung cấp) cũng biên dịch chương trình với cấu hình tương đương.

## Quy ước nhập ngày tháng

- Dạng nhập bắt buộc: `dd/mm/yyyy`. Ví dụ `05/11/2025`.
- Hàm `nhap_ngay_thang_nam` kiểm tra hợp lệ, yêu cầu nhập lại nếu sai.
- Việc cộng ngày/ tháng sử dụng giả định 1 tháng = 30 ngày, 1 năm = 12 tháng nhằm đơn giản hóa bài tập nhập môn.

## Giới hạn & ghi chú

- Không có dữ liệu mẫu khởi tạo; hãy nhập thủ công khi thử nghiệm.
- Khi thay đổi tổng số lượng sách, chương trình bảo toàn số bản đang được mượn; nếu đặt tổng nhỏ hơn số đang mượn, số còn lại bị ép về 0.
- Các báo cáo “trễ hạn” cần người dùng cung cấp ngày hiện tại vì không dùng được `time.h`.
- Chương trình không hỗ trợ undo/redo, không đồng bộ đa người dùng.

## Đóng góp & mở rộng

Người dùng có thể mở rộng chương trình bằng cách thêm các hàm ở đúng module tương ứng. Hãy giữ nguyên quy ước:

- Mỗi hàm có chú thích ngắn gọn nêu nhiệm vụ/ tham số/ giá trị trả về.
- Tất cả dữ liệu lưu trong mảng một chiều và biến toàn cục được khai báo bằng `extern` trong file header.
- Nếu cần thêm thống kê mới, bổ sung vào `stats.c` và cập nhật trình đơn thống kê trong `main.c`.
📝 License
Dự án này được phát triển cho mục đích học tập và nghiên cứu.

Phát triển như một phần của đồ án môn Nhập môn lập trình - 2025
