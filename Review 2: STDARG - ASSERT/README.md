> https://docs.google.com/document/d/12lmmSJiRA9i2y9HqExIGrHih4RxUOakloIKhXuoMEk4/edit

## Bài Tập: Hệ Thống Điều Khiển Thiết Bị IoT
**1, Mô Tả**  

Bạn được yêu cầu viết một chương trình mô phỏng hệ thống điều khiển các thiết bị IoT trong một ngôi nhà thông minh. Hệ thống này phải có khả năng xử lý các lệnh đến từ người dùng để điều khiển các thiết bị như đèn, điều hòa, khóa cửa vân tay, và trình phát nhạc.

**2, Yêu Cầu**

+ Xử lý Lệnh Điều Khiển:
    Đèn: Bật/Tắt.
    Điều hòa: Bật/Tắt, Thay đổi nhiệt độ, Đổi chế độ làm mát/quạt gió.
    Khóa cửa vân tay: Mở/Khóa.
    Trình phát nhạc: Bật/Tắt, Tăng/Giảm âm lượng, Đổi bài hát.
+ Input: Chương trình nhận input dưới dạng các lệnh từ người dùng. Mỗi lệnh bao gồm loại thiết bị và hành động cần thực hiện, cùng với các tham số cần thiết.
+ Output: Chương trình sẽ in ra thông báo chi tiết về hành động được thực hiện cho mỗi lệnh.
+ Ví Dụ
      Input: controlDevice(LIGHT, ON);
      Output: Light turned ON
      Input: controlDevice(AIR_CONDITIONER, SET_TEMPERATURE, 24);
      Output: Air Conditioner temperature set to 24 degrees

**3, Nhiệm Vụ**

+ Viết hàm controlDevice để xử lý các lệnh nhập vào.
+ Xác định và xử lý các trường hợp khác nhau dựa trên loại thiết bị và loại lệnh.
+ In ra thông báo tương ứng với mỗi hành động được thực hiện.
+ Gợi Ý
> Sử dụng switch case để xử lý các loại thiết bị và lệnh khác nhau.
> Sử dụng stdarg.h để xử lý số lượng và loại tham số đầu vào không xác định.
+ Kiểu dữ liệu các bạn có thể sử dụng
  
      typedef enum {
          LIGHT,
          AIR_CONDITIONER,
          FINGERPRINT_LOCK,
          MUSIC_PLAYER
      } DeviceType;
      
      typedef enum {
          ON,
          OFF,
          SET_TEMPERATURE,
          SET_MODE,
          UNLOCK,
          LOCK,
          INCREASE_VOLUME,
          DECREASE_VOLUME,
          CHANGE_TRACK
      } CommandType;


