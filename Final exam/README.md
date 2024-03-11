> https://docs.google.com/document/d/1QFZN27WOXQBWee3aI9pWt60AXK7fgzHJ1d_WmJNUNDc/edit

# Chức năng của máy thanh toán tiền trong siêu thị
## I. Thêm sản phẩm vào giỏ hàng:
### 1. Tìm kiếm và chọn sản phẩm:
+ Người dùng sử dụng giao diện máy thanh toán để tìm kiếm sản phẩm mình muốn mua. Giao diện có thể cung cấp một ô tìm kiếm để người dùng nhập từ khóa hoặc danh mục sản phẩm để duyệt.
+ Sau khi tìm thấy sản phẩm mong muốn, người dùng chọn sản phẩm đó bằng cách nhấn vào nút hoặc chạm vào màn hình.
### 2. Kiểm tra số lượng trong kho:
+ Khi sản phẩm được chọn, máy thanh toán sẽ kiểm tra số lượng của sản phẩm đó trong kho.
+ Nếu số lượng sản phẩm đủ để đáp ứng yêu cầu mua của người dùng, quá trình thêm sản phẩm vào giỏ hàng sẽ tiếp tục.
+ Nếu số lượng sản phẩm không đủ hoặc sản phẩm đã hết hàng, máy thanh toán sẽ hiển thị thông báo cảnh báo cho người dùng, cho biết sản phẩm không khả dụng để mua và không thêm sản phẩm vào giỏ hàng.
### 3. Thêm sản phẩm vào giỏ hàng:
+ Nếu sản phẩm có sẵn và số lượng đủ, sản phẩm sẽ được thêm vào giỏ hàng của người dùng.
+ Mỗi sản phẩm được thêm vào giỏ hàng sẽ hiển thị trong danh sách giỏ hàng trên giao diện, bao gồm thông tin như tên sản phẩm, giá tiền, và số lượng.
+ Người dùng có thể tiếp tục tìm kiếm và thêm các sản phẩm khác vào giỏ hàng hoặc tiến hành thanh toán khi họ đã chọn đủ sản phẩm mong muốn.
## II. Xóa sản phẩm khỏi giỏ hàng:
### 1. Xem danh sách sản phẩm trong giỏ hàng:
+ Người dùng có thể xem danh sách các sản phẩm đã thêm vào giỏ hàng trên giao diện máy thanh toán. Danh sách này thường được hiển thị dưới dạng một bảng hoặc danh sách có thể cuộn.
### 2. Loại bỏ sản phẩm không muốn mua:
+ Người dùng chọn sản phẩm mà họ muốn loại bỏ khỏi giỏ hàng. Điều này có thể được thực hiện bằng cách nhấn vào nút "Xóa" hoặc "Loại bỏ" liên kết với sản phẩm đó trên giao diện.
### 3. Cập nhật giỏ hàng:
+ Khi người dùng chọn loại bỏ một sản phẩm, máy thanh toán sẽ cập nhật giỏ hàng bằng cách loại bỏ sản phẩm đó khỏi danh sách.
+ Danh sách giỏ hàng sẽ được cập nhật tự động để phản ánh thay đổi, và sản phẩm đã loại bỏ sẽ không còn xuất hiện trong danh sách nữa.
### 4. Cập nhật số lượng trong kho:
+ Sau khi sản phẩm được loại bỏ khỏi giỏ hàng, máy thanh toán sẽ cập nhật lại số lượng của sản phẩm trong kho.
+ Số lượng sản phẩm được loại bỏ sẽ được cộng lại vào số lượng có sẵn trong kho để đảm bảo thông tin về số lượng sản phẩm là chính xác.
### 5. Thông báo cập nhật:
+ Sau khi sản phẩm đã được loại bỏ khỏi giỏ hàng và số lượng trong kho đã được cập nhật, máy thanh toán có thể hiển thị một thông báo xác nhận cho người dùng để thông báo rằng thao tác đã được thực hiện thành công.
## III. Tính toán tổng tiền:
### 1. Tính toán tổng tiền khi thêm sản phẩm vào giỏ hàng:
+ Mỗi khi người dùng thêm một sản phẩm vào giỏ hàng, máy thanh toán sẽ cập nhật tổng số tiền cần thanh toán bằng cách thêm giá của sản phẩm đó vào tổng số tiền hiện có.
+ Giá của sản phẩm được lấy từ dữ liệu sản phẩm trong kho.
+ Nếu người dùng thêm nhiều sản phẩm cùng loại, tổng số tiền sẽ được tính bằng cách nhân giá của sản phẩm đó với số lượng.
### 2. Tính toán tổng tiền khi loại bỏ sản phẩm khỏi giỏ hàng:
+ Khi người dùng loại bỏ một sản phẩm khỏi giỏ hàng, máy thanh toán sẽ cập nhật tổng số tiền cần thanh toán bằng cách trừ giá của sản phẩm đó khỏi tổng số tiền hiện có.
+ Giá của sản phẩm được lấy từ dữ liệu sản phẩm trong kho.
+ Nếu người dùng loại bỏ nhiều sản phẩm cùng loại, tổng số tiền sẽ được tính bằng cách trừ giá của sản phẩm đó nhân với số lượng khỏi tổng số tiền.
### 3. Hiển thị tổng tiền:
+ Mỗi khi có thay đổi trong giỏ hàng (thêm hoặc loại bỏ sản phẩm), máy thanh toán sẽ hiển thị tổng số tiền cần thanh toán mới trên giao diện người dùng.
+ Tổng số tiền được hiển thị một cách rõ ràng và dễ đọc, bên cạnh danh sách sản phẩm trong giỏ hàng.
## IV. Thực hiện thanh toán:
### 1. Chọn phương thức thanh toán:
+ Sau khi người dùng đã hoàn tất việc chọn sản phẩm và kiểm tra giỏ hàng, họ sẽ chọn phương thức thanh toán trên giao diện máy thanh toán.
+ Phương thức thanh toán có thể bao gồm các lựa chọn như thanh toán bằng tiền mặt, thẻ tín dụng/debit, ví điện tử, hoặc các phương thức thanh toán trực tuyến khác.
### 2. Xử lý thanh toán:
+ Sau khi chọn phương thức thanh toán, máy thanh toán sẽ bắt đầu xử lý quá trình thanh toán.
+ Nếu người dùng chọn thanh toán bằng tiền mặt, máy thanh toán sẽ hiển thị tổng số tiền cần thanh toán và yêu cầu người dùng nhập số tiền mặt trả. Sau đó, máy thanh toán sẽ tính toán số tiền thối lại (nếu có) và hoàn tất quá trình thanh toán.
+ Nếu người dùng chọn thanh toán bằng thẻ tín dụng/debit hoặc các phương thức thanh toán điện tử, họ sẽ được yêu cầu nhập thông tin thanh toán cần thiết (ví dụ: thông tin thẻ tín dụng/debit hoặc đăng nhập vào tài khoản ví điện tử). Máy thanh toán sẽ gửi thông tin thanh toán đến hệ thống ngân hàng hoặc đối tác thanh toán điện tử để xác nhận và hoàn tất thanh toán.
### 3. Xử lý kết quả thanh toán:
+ Sau khi quá trình thanh toán được hoàn tất, máy thanh toán sẽ hiển thị kết quả thanh toán cho người dùng.
+ Nếu thanh toán thành công, máy thanh toán sẽ cung cấp hóa đơn hoặc biên nhận cho người dùng và thông báo rằng giao dịch đã hoàn tất.
+ Nếu có lỗi xảy ra trong quá trình thanh toán, máy thanh toán sẽ hiển thị thông báo lỗi phù hợp và hướng dẫn người dùng cách xử lý.
### 4. Hoàn tất giao dịch:
+ Sau khi giao dịch thanh toán được hoàn tất, máy thanh toán sẽ cập nhật trạng thái của các sản phẩm trong kho (nếu cần) và chuẩn bị cho giao dịch mua hàng tiếp theo.
## V. Cập nhật kho:
### 1. Xác nhận thanh toán thành công:
+ Sau khi quá trình thanh toán được hoàn tất và người dùng đã nhận được xác nhận thanh toán, máy thanh toán sẽ bắt đầu quá trình cập nhật kho.
### 2. Giảm số lượng sản phẩm đã mua từ tổng số lượng có sẵn:
+ Máy thanh toán sẽ lấy thông tin về các sản phẩm đã mua và số lượng tương ứng từ giỏ hàng hoặc hóa đơn thanh toán.
+ Dựa trên thông tin này, máy thanh toán sẽ cập nhật số lượng của mỗi sản phẩm trong kho bằng cách giảm số lượng đã mua từ tổng số lượng có sẵn.
+ Cập nhật số lượng này sẽ đảm bảo rằng kho luôn được cập nhật chính xác và đồng bộ với số lượng thực tế của các sản phẩm.
### 3. Lưu trữ lịch sử giao dịch (tuỳ chọn):
+ Tuỳ thuộc vào yêu cầu của hệ thống, máy thanh toán có thể lưu trữ thông tin về giao dịch thanh toán để dễ dàng theo dõi và kiểm tra sau này.
+ Thông tin về giao dịch bao gồm các chi tiết như danh sách sản phẩm mua, số lượng, giá tiền, phương thức thanh toán và thời gian giao dịch.
### 4. Hiển thị thông báo cập nhật thành công (tuỳ chọn):
+ Sau khi cập nhật kho thành công, máy thanh toán có thể hiển thị một thông báo xác nhận cho người dùng, thông báo rằng quá trình cập nhật kho đã được hoàn tất.
## VI. Xử lý trường hợp đặc biệt:
### 1. Số lượng sản phẩm không đủ hoặc sản phẩm đã hết hàng:
+ Khi người dùng thêm một sản phẩm vào giỏ hàng nhưng số lượng trong kho không đủ hoặc sản phẩm đã hết hàng, máy thanh toán sẽ hiển thị một thông báo cảnh báo trên giao diện người dùng.
+ Thông báo này sẽ cung cấp thông tin chi tiết về tình trạng của sản phẩm và hướng dẫn người dùng về các tùy chọn khác, như chọn sản phẩm thay thế hoặc chờ đợi sản phẩm trở lại kho.
### 2. Xử lý lỗi trong quá trình thanh toán:
+ Trong trường hợp có lỗi xảy ra trong quá trình thanh toán, ví dụ như thẻ bị từ chối hoặc lỗi kết nối mạng, máy thanh toán sẽ hiển thị một thông báo lỗi phù hợp.
+ Thông báo lỗi sẽ cung cấp một mô tả ngắn gọn về lỗi xảy ra và hướng dẫn người dùng cách xử lý vấn đề, bao gồm các hướng dẫn như kiểm tra lại thông tin thẻ, thử lại sau một khoảng thời gian nhất định, hoặc liên hệ với nhân viên hỗ trợ.
### 3. Xử lý các trường hợp đặc biệt khác:
+ Ngoài các trường hợp đã nêu, máy thanh toán cũng cần xử lý các trường hợp đặc biệt khác có thể xảy ra trong quá trình mua sắm và thanh toán.
+ Các trường hợp này có thể bao gồm việc quét mã vạch bị lỗi, nhập thông tin sản phẩm bằng tay, hoặc các vấn đề kỹ thuật khác.
+ Máy thanh toán cần có các cơ chế xử lý phù hợp và hiển thị thông báo hướng dẫn chi tiết để giúp người dùng vượt qua các tình huống đặc biệt này một cách dễ dàng và thuận tiện.
