# Lý thuyết C

# 1. Phân vùng nhớ

- Trong RAM được chia thành 5 vùng nhớ :
    - Data section
    - Bss section
    - Text section
    - Heap section
    - Stack section

## 1.1 Data section

- Là vùng chứa các biến hằng, chỉ có thể đọc, không thể ghi
- Là vùng chứa các biến toàn cục hay biến static có giá trị khởi tạo. Các biến này sẽ tồn tại suốt trong chương trình và có thể đọc và ghi,

## 1.2 Bss section

- Là vùng nhớ được sử dụng để lưu trữ các biến toàn cục và biến static không có giá trị khởi tạo
- Các biến này có đặc điểm là có thể đọc và ghi được

## 1.3 Text section

- Là vùng nhớ được sử dụng để lưu giữ phần code, các câu lệnh được biên dịch trong chương trình.
- Đây là vùng được quản lí bởi hệ điều hành và ta không thể thực hiện các thao tác trên vùng này

## 1.4 Heap section

- Là vùng nhớ được sử dụng để cấp phát bộ nhớ động, Calloc, Malloc.
- Đặc điểm của vùng này là nó không tự mất đi trong quá trình chạy mà chúng ta phải sử dụng từ khóa free để giải phóng bộ nhớ. Nếu không giải phóng thì vùng nhớ này có thể đầy và gây ra lỗi

## 1.5 Stack section

- Là vùng nhớ được sử dụng để lưu các biến cục bộ trong hàm,các biến này có thể đọc và ghi được, sẽ bị giải phóng khi thoát ra khỏi hàm
- Ngoài ra, khi xảy ra ngắt hay ngoại lệ thì trạng thái và địa chỉ của câu lệnh hiện tại sẽ được lưu vào stack (stacking) và sẽ được trả lại sau khi hoàn thành xong chương trình ngắt (Unstacking)

# 2. Struct và Union

## 2.1 Struct

- Là một kiểu dữ liệu được người dùng định nghĩa, bao gồm 1 hoặc nhiều member
- Kích cỡ của một struct là tổng các kích cỡ của các member và cộng thêm phần padding
- Mỗi lần quét được bao nhiêu byte phụ thuộc vào kiến trúc của máy tính, nếu máy 32 bit thì mỗi lần quét là 4 bytes, đối với máy 64 bit thì mỗi lần quét là 8 bytes

## 2.2 Union

- Tương tự như Struct nhưng chỉ khác là các member được sử dụng chung một bộ nhớ
- Kích cỡ của Union là bằng kích cỡ của member lớn nhất
- Nếu chúng ta thực hiện gán giá trị cho các member trong Union thì các member gán giá trị sau sẽ ghi đè lên giá trị của các member trước vì chúng chỉ sử dụng chung 1 bộ nhớ, dẫn đến việc khi ta thay đổi giá trị của 1 member thì sẽ làm thay đổi giá trị của các member khác

# 3. Con trỏ

- Con trỏ là một kiểu dữ liệu, lưu trữ địa chỉ của một biến , hàm  hay là của một con trỏ khác.
- Con trỏ void : là con trỏ có thể trỏ tới bất kì địa chỉ của biến nào VD như biến ở kiểu int, char, double,…
- Khi khai báo con trỏ thì ta phải gán giá trị cho nó để tránh việc nó trỏ đến địa chỉ ngẫu nhiên làm ảnh hưởng đến chương trình. Nếu chưa thể gán giá trị thì ta nên gán = con trỏ NULL
- Con trỏ hàm là con trỏ được sử dụng để trỏ tới một function trong chương trình.
- Con trỏ cấp 2 là con trỏ trỏ tới địa chỉ của một con trỏ khác trong chương trình

# 4. Macro và Function

- Macro là chúng ta thay thế đoạn code của chương trình bằng một đoạn text để thuận tiện trong quá trình lập trình và chương trình sẽ chạy đoạn code được thay thế mỗi khi mà macro được gọi đến.
- Macro được thực hiện bởi Proprocessor
- Function là một chương trình con được khai báo và định nghĩa bên ngoài chương trình chính. Chương trình sẽ chạy sang Function mỗi khi Function đó được gọi
- Quá trình này tốn thời gian và bộ nhớ của máy hơn Macro vì chương trình sẽ phải lưu địa chỉ của câu lệnh trước khi gọi hàm (PC) và trả lại sau khi thực hiện xong hàm để chạy tiếp chương trình

# 5. Biến static

- Là biến chỉ được khởi tạo 1 lần duy nhất trong chương trình và nó tồn tại trong suốt chương trình
- Ta có thể đọc và ghi biến này
- Biến static toàn cục thì chỉ có thể được truy cập tại file khai báo nó, không thể truy cập ở các file khác với từ khóa “extern”
- Biến static cục bộ thì được khai báo 1 lần và nó không bị giải phóng khi thoát khỏi hàm, tồn tại trong suốt chương trình
- Khi gọi biến static thì giá trị của nó chính là giá trị tại lần gần nhất được gọi
- Nó chỉ có thể được gọi trong nội bộ hàm khai báo nó.
