# Điều chỉnh điều hòa nhiệt độ trên xe ô tô bằng 2 chế độ 
1. Chế độ bằng tay
2. Chế độ tự động

Main
- Task 1: Luồng giao diện ng dùng (Màn hình hiển thị) 
    + Nhiệt độ bên trong xe -> nút tăng nhiệt độ và nút giảm nhiệt độ
    + Mức gió bên trong xe -> nút tăng mức gió và nút giảm mức gió (mức gió gồm 5 nấc)
- Task 2: Luồng sensor nhiệt độ bên ngoài xe
    + vector <float> temp = [17.4, 16.7, 14.6, ...]
    + delay(500) // Cứ 500ms gởi về cho main
- Task 3: Luồng sensor nhiệt độ bên trong xe 
    + vector <float> temp = [17.4, 16.7, 14.6, ...]
    + delay(500) // Cứ 500ms gởi về cho main
- Task 4: Luồng điều khiển điều hòa nhiệt độ
    + tăng nhiệt độ
    + giảm nhiệt độ
- Task 5: Luồng điều khiển quạt gió (5 level; 0 là tắt quạt gió)
    + tăng nhiệt độ
    + giảm nhiệt độ
