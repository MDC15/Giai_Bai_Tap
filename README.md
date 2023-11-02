Trong mã nguồn trên, tôi đã sử dụng các kiến trúc sau:

- Cấu trúc dữ liệu: Tôi đã sử dụng cấu trúc dữ liệu vector<vector<Cell>> để lưu trữ bàn cờ. Cấu trúc dữ liệu này cho phép tôi truy cập các ô trên bàn cờ một cách hiệu quả.
- Lập trình hướng đối tượng: Tôi đã sử dụng lập trình hướng đối tượng để tạo lớp Board. Lớp này cung cấp các hàm để đọc bàn cờ, kiểm tra ô bị bao vây, tính diện tích vùng đất và xác định bên thắng cuộc.
- Thuật toán: Tôi đã sử dụng thuật toán kiểm tra ô bị bao vây dựa trên quy tắc "các ô xung quanh có cùng màu". Thuật toán này có thể xác định chính xác ô nào bị bao vây trong tất cả các trường hợp.
  Dưới đây là một số chi tiết cụ thể về cách tôi đã sử dụng các kiến trúc này:
- Cấu trúc dữ liệu: Tôi đã sử dụng cấu trúc dữ liệu vector<vector<Cell>> để lưu trữ bàn cờ. Mỗi ô trên bàn cờ được đại diện bởi một cấu trúc Cell. Cấu trúc này có hai trường: value và isOccupied. Trường value lưu trữ giá trị của ô ('O' hoặc 'X'). Trường isOccupied cho biết liệu ô đó đã được chiếm hay chưa.
- Lập trình hướng đối tượng: Tôi đã sử dụng lập trình hướng đối tượng để tạo lớp Board. Lớp này có ba thành viên:
  - board\_: Một mảng hai chiều lưu trữ các ô trên bàn cờ.
  - ReadBoard(): Hàm đọc bàn cờ từ tệp.
  - GetWinner(): Hàm xác định bên thắng cuộc.
- Thuật toán: Tôi đã sử dụng thuật toán kiểm tra ô bị bao vây dựa trên quy tắc "các ô xung quanh có cùng màu". Thuật toán này hoạt động như sau:

  1.  Kiểm tra tất cả các ô xung quanh ô (i, j).
  2.  Nếu tất cả các ô xung quanh ô (i, j) có cùng màu với ô (i, j), thì ô (i, j) được coi là bị bao vây.

  By MDC
