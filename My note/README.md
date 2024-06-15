# NHỮNG ĐIỀU CƠ BẢN VỀ NGÔN NGỮ LẬP TRÌNH C
> https://drive.google.com/file/d/1bfNs8DcXfcF7pu1ee3z3_6MWsvbn_Zow/view?usp=sharing
## namespace
> https://viblo.asia/p/namespace-trong-c-XL6lAv0R5ek
> https://www.w3schools.in/cplusplus/namespace
## thread
> https://livebook.manning.com/book/c-plus-plus-concurrency-in-action/chapter-1/1

## Lập trình bằng ngôn ngữ nào?
- Máy tính đúng là một cỗ máy kì lạ: nó chỉ nhận và gửi lại những số 0 và 1.
- Ví dụ, nếu dịch câu: “thực hiện phép tính 3 + 5” về ngôn ngữ máy tính, nó sẽ có dạng như sau: 0010110110010011010011110. Những số này, là ngôn ngữ của máy tính, gọi là ngôn ngữ nhị phân (language binary). Máy tính của bạn chỉ hiểu đươc ngôn ngữ này. Nhưng bạn và tôi, chúng ta hoàn toàn không thể hiểu và học được ngôn ngữ đó.

=> Đây chính là vấn đề đầu tiên của chúng ta: Làm cách nào để giao tiếp với máy tính đơn giản hơn việc dùng những số 0 hay 1? Máy tính của bạn không nói được tiếng Anh cũng như tiếng Việt. Và không ai quan niệm phải viết một chương trình bằng ngôn ngữ nhị phân, kể cả những nhà lập trình điên nhất cũng không làm chuyện đó.

- Ý tưởng là phải tạo ra một ngôn ngữ mới đơn giản hơn và sau đó nó sẽ được chuyển sang ngôn ngữ nhị phân. Đây là việc của những nhà lập trình chuyên về ngôn ngữ. Và các chương trình trình này đã đuợc tạo ra bởi họ, chúng ta sẽ không cần phải thực hiện lại.
- Dưới đây là biểu đồ giúp bạn hiểu rõ hơn: (Biểu đồ cực kì đơn giản về việc thi hành một chương trình)

![image](https://github.com/minchangggg/Advanced_C/assets/125820144/d2aa9dab-1901-4788-a8f9-6e29d0453adb)

    + Trong ô đầu tiên: “Chương trình được viết bằng ngôn ngữ lập trình đơn giản”. Cụm từ “Ngôn ngữ lập trình đơn giản” còn đuợc gọi là “ngôn ngữ bậc cao”. (high-level programming language). Có rất nhiều “cấp bậc” trong ngôn ngữ lập trình. Và ngôn ngữ bậc càng cao càng gần và giống với ngôn ngữ của chúng ta (cũng giống như tiếng Việt hay tiếng Anh). Ngôn ngữ bậc cao giúp ta dễ dàng hơn trong sử dụng, nhưng nó vẫn có một vài thiếu sót mà bạn sẽ thấy về sau. Có rất nhiều ngôn ngữ bậc cao hay thấp trong tin học, trong số đó bạn có thể dùng để lập trình. Và đây là một vài ví dụ: C, C++, Java, Visual Basic, Delphi, ..vv..
    + Trong giai đoạn tiếp theo, “chương trình biên dịch” sẽ dịch ngôn ngữ bậc cao đó (C hay C++) sang nhị phân. Chương trình này có tên là compiler. Việc biên dịch gọi là compilation.
    > Quan trọng: các ngôn ngữ lập trình bậc cao khác nhau sẽ có các compiler khác nhau. Nói cách khác, chúng ta không thể dịch ngôn ngữ C++ cùng với cách mà ta dịch ngôn ngữ Delphi.
    >
    > Về sau bạn sẽ nhận thấy, cùng một ngôn ngữ sẽ có nhiều compilers khác nhau (compiler của Microsoft, compiler GNU...). Rất may mắn là những compiler đó gần như giống nhau (đôi khi chúng có những khác biệt nhỏ và tôi sẽ chỉ cho bạn).
    + Cuối cùng, chương trình nhị phân được tạo ra bởi compiler được gọi là: executable. Các chương trình này trên Windows có đuôi “.exe” giống như EXEcutable.
    
    => Quay lại với biểu đồ vừa rồi nhưng thay bằng những thuật ngữ tin học chính xác

## Những công cụ cần thiết cho việc lập trình
<img width="20" alt="image" src="https://github.com/minchangggg/Advanced_C/assets/125820144/191efbf2-8449-428b-a966-943b669130ad"> 
Dưới đây là những hành trang tối thiểu cho một lập trình viên:

+ Một chương trình soạn thảo văn bản (**text editor program**) để viết mã nguồn (source code) của chương trình. Trên lý thuyết thì để thực hiện việc này chúng ta chỉ cần sử dụng phần mềm “Notepad” trong Windows hoặc “Vi” trong Linux là đủ. Nhưng sẽ lý tưởng hơn khi bạn sử dụng một trình soạn thảo văn bản có thể tô đậm màu sắc các thành phần trong mã nguồn nhằm giúp bạn xác định rõ ràng hơn khi cần thiết.
+ Một chương trình biên dịch mã nguồn (**compiler**) để giúp dịch ngôn ngữ lập trình C/C++ của bạn sang ngôn ngữ nhị phân của máy tính.
+ Một chương trình tìm và sửa lỗi (**debugger**) để giúp bạn theo dõi các lỗi trong chương trình của mình. Tin không vui là cho tới bây giờ chúng ta vẫn chưa phát minh ra chức năng “hiệu chỉnh” để sữa chữa những lỗi của chương trình. Điều đó cũng đồng nghĩa với việc nếu bạn đã nắm rõ cách hoạt động của debugger, nó sẽ giúp bạn tìm ra lỗi một cách dễ dàng, chỉ vậy thôi.

<img width="20" alt="image" src="https://github.com/minchangggg/Advanced_C/assets/125820144/191efbf2-8449-428b-a966-943b669130ad"> 
Từ những điều trên chúng ta sẽ thấy có 2 trường hợp:

+ TH1: Để lập trình, chúng ta sẽ phải dùng 3 chương trình riêng biệt, và đây cũng là cách phức tạp nhất, nhưng sự thật là nó có thể hoạt động. Chẳng hạn như với Linux, nhiều lập trình viên vẫn thích sử dụng 3 chương trình riêng biệt cho công việc lập trình của họ. Tôi sẽ không nói chi tiết về việc này trong bài này mà tôi sẽ chỉ bạn một cách đơn giản hơn.
+ TH2: Chúng ta có chương trình nào bao gồm 3 trong 1 không? Tức là một chương trình có chứa 3 thằng “text editor”, “compiler” và “debugger”. Câu trả lời là có và người ta gọi những chương trình này là IDE.

## Console hay là cửa sổ?
<img width="20" alt="image" src="https://github.com/minchangggg/Advanced_C/assets/125820144/191efbf2-8449-428b-a966-943b669130ad"> 
Có 2 loại chương trình :

+ Những chương trình dạng cửa sổ.
+ Những chương trình dạng console.

a. Những chương trình dạng cửa sổ
- Ví dụ điển hình cho một chương trình dạng cửa sổ:

<img width="600" alt="image" src="https://github.com/minchangggg/Advanced_C/assets/125820144/50000e2a-e200-4de3-98e7-8d7173dcc917"> 

b. Những chương trình dưới dạng console:
- Console chính là những chương trình xuất hiện đầu tiên trên thế giới. Vào thời kì đó, máy tính chỉ có khả năng tạo ra những dòng chữ đen và trắng và không đủ mạnh để hiển thị những cửa sổ
nhiều màu sắc và hiệu ứng như bạn thấy hiện nay.
- Sau đó, Windows đã cho ra đời máy tính có khả năng chạy những chương trình dạng cửa sổ. Vì vậy mà sản phẩm của họ được dùng rộng rãi, khiến phần lớn người sử dụng quên mất sự tồn tại
của console.
- Và tôi chắc là bạn đang muốn biết console là gì phải không? Đây là hình ảnh của console trên Linux:

<img width="600" alt="image" src="https://github.com/minchangggg/Advanced_C/assets/125820144/d36bcbfe-5d2a-4055-831d-670a00a67c87"> 

- Đó là console và những đặc điểm cần chú ý là:

  + Console ngày nay không chỉ hiển thị trắng và đen.
  + Console không được những người mới sử dụng chào đón lắm.
  + Console là một công cụ mạnh mẽ nếu như chúng ta biết cách sử dụng.
    
- Viết một chương trình dạng console đơn giản và lý tưởng hơn cho những người mới học lập trình (sẽ không hề đơn giản nếu bắt đầu học bằng cách tạo ra một chương trình dạng cửa sổ)
- Ghi thêm rằng, console ngày nay đã được cải tiến rất nhiều: hiển thị được nhiều màu sắc, và bạn có thể đặt một hình ảnh nào đó lên nền của console. Và đây là hình ảnh một console đã được tạo dựng khá hoành tráng trên HĐH linux.

<img width="600" alt="image" src="https://github.com/minchangggg/Advanced_C/assets/125820144/3589cfef-b981-4f2d-a695-eb3ca2cf570e"> 

- Hình ảnh console của Windows:

<img width="600" alt="image" src="https://github.com/minchangggg/Advanced_C/assets/125820144/598c5948-edc2-46bd-838d-6bb1d3e912c0"> 

## Những dòng code tối thiểu 
<img width="700" alt="image" src="https://github.com/minchangggg/Advanced_C/assets/125820144/28bd06da-7477-4e1a-ae07-bf28bd6cc69f"> 

                    /*
                    - Đây chính là những dòng đặc biệt thường thấy ở đầu những file source và dễ dàng nhận biết vì nó bắt đầu từ dấu “#”. Ta gọi chúng là preprocessor directives (những chỉ thị tiền xử lý) vì nó
                    sẽ được đọc bằng một chương trình gọi là preprocessor (chương trình tiền xử lý), chương trình này sẽ chạy đầu tiên khi ta thực hiện compilation.
                    - Chúng ta đã thấy hình vẽ đơn giản về compilation ở chương trước. Nhưng quá trình đó thực sự không hề dễ dàng như vậy, có rất nhiều thứ diễn ra trong đó. Tôi sẽ nói sau này, tại thời điểm hiện tại, các bạn chỉ cần biết cách viết những dòng đầu tiên vào file của bạn là đủ. Nhưng những dòng đó nghĩa là gì? Tôi rất muốn biết điều đó!
                    - Từ “include” tiếng Anh có nghĩa là đặt vào, bao gồm. Nó cho phép thêm vào project một số file. Những file này sẽ được sử dụng trong quá trình compilation.
                    - Ở đây có 2 dòng, vậy là sẽ có 2 file được thêm vào. Những file này có tên là stdio.h và stdlib.h. Đó là những file đã tồn tại trước đó trong source và luôn sẵn sàng khi bạn gọi ra. Chúng ta thường gọi nó là thư viện (library). Và những file này chứa những đoạn code được viết sẵn cho
                    phép hiển thị một đoạn văn lên màn hình.
                    - Nếu không có những file thư viện đó, ta không thể nào ghi được một đoạn văn lên màn hình.  
                    => Tóm lại, 2 dòng đầu tiên đó cho phép ta ghi một tin nhắn lên màn hình "dễ dàng", giúp máy tính hiểu bạn muốn làm gì.
                    */
                    #include <stdio.h>
                    #include <stdlib.h>
                    /*
                   - Đây là một function. Một chương trình C hầu như cấu tạo bởi các function, Tại thời điểm này, chương trình của chúng ta chỉ có một function duy nhất.
                   - Một function cho phép chúng ta tập hợp lại các lệnh cho máy tính, những lệnh này cho phép ta thực hiện chính xác một điều gì đó. Ví dụ, ta có thể viết một function “mở_một_tập_tin” trong đó chứa đựng những chỉ dẫn về cách mở một tập tin cho máy tính.
                   - Lợi ích là, một khi function đã được viết ra, bạn không cần phải nói thêm gì nữa cả. Máy tính sẽ biết làm việc đó bằng cách nào.
                   - Vẫn còn quá sớm để chúng ta tìm hiểu chi tiết về những thành phần cấu tạo nên một function, chúng ta chỉ xem xét những phần chính của nó. Ở câu đầu tiên, chữ thứ hai (main) là tên của function. Theo nguyên tắc, main là một tên đặc biệt, nó chỉ dùng để đặt cho function chính của chương trình, và lúc nào chương trình cũng sẽ bắt đầu từ function main. Một function luôn có mở đầu và kết thúc, giới hạn bởi những dấu { và }. Tất cả function main của chúng ta đều nằm trong đó. Nếu bạn đã theo kịp những gì tôi đã nói, thì function main của chúng ta gồm 2 dòng gọi là các instruction
                    */
                    int main(int argc, char *argv[])
                    {
                     printf ("Xin chao"); // instruction nay hien thi “Xin chao” len man hinh
                     return 0; // Chuong trinh tra ve gia tri 0 va ket thuc
                    }

## Công việc của bộ nhớ
- Con người cũng như máy tính đều cần lưu giữ lại một số cái gì đó, con người chỉ có duy nhất bộ não nhưng trên máy tính thì có nhiều dạng bộ nhớ khác nhau.

**Tại sao máy tính cần nhiều loại bộ nhớ khác nhau? Một bộ nhớ duy nhất không đủ cho máy tính, có phải vậy không?**

- Không, thực tế người ta chỉ cần một bộ nhớ có tốc độ lưu nhanh và khả năng chứa lớn (để có thể lưu lại nhiều thứ quan trọng).
- Nhưng cho đến thời điểm hiện tại, chúng ta vẫn chưa tạo được những bộ nhớ giống như vậy.
- Vì các bộ nhớ nhanh thì đắt tiền nên các bộ nhớ được tổ chức thành nhiều cấp, cấp có dung lượng ít thì nhanh nhưng đắt tiền hơn cấp có dung lượng cao hơn. Những bộ nhớ có tốc độ lưu càng nhanh sẽ có dung lượng càng nhỏ.
- Vậy máy tính của chúng ta được lắp đặt gồm:
  
    + Những bộ nhớ có tốc độ lưu nhanh nhưng khả năng chứa nhỏ.
    + Những bộ nhớ có tốc độ lưu chậm nhưng khả năng chứa lớn hơn rất nhiều
      
**Những khác biệt về bộ nhớ?**

- Để cho dễ hiểu, đây là những loại bộ nhớ khác nhau có trong một máy tính được sắp xếp từ nhanh đến chậm:
  
    1. Registers: Bộ nhớ cực nhanh được đặt trực tiếp trong bộ xử lý của máy tính (processor).
    2. Memory cache: Làm cầu nối giữa registers và RAM.
    3. Main memory (RAM): Là một bộ nhớ mà chúng ta sử dụng thường xuyên nhất.
    4. Ổ cứng (Hard Disk Drive): Cái này các bạn biết đến nhiều nhất, người ta thường lưu trữ dữ liệu ở đây.
       
- Những registers chỉ có thể chứa được một vài số, trái ngược hẳn với ổ cứng có thể chứa một số lượng lớn các tập tin.
- Chỉ có ổ cứng giữ lại tất cả những gì mà nó chứa. Tất cả các bộ nhớ khác (registers, Memory cache, RAM) đều là những bộ nhớ nhất thời: khi mà bạn tắt máy tính đi thì tất cả dữ liệu trong đó sẽ mất đi.

**a. Hình ảnh của RAM**
- Các bạn đã biết thế nào là bàn phím, chuột, màn hình và thùng máy. Bây giờ chúng ta chỉ quan tâm đến thùng máy của bạn, trung tâm của máy tính, nó chứa tất cả các loại bộ nhớ.
- Dưới đây là hình ảnh của ram:
  
<img width="400" alt="image" src="https://github.com/minchangggg/Advanced_C/assets/125820144/5e589f29-f894-4424-b011-5d99bea19431"> 

**b. Biểu đồ của RAM**

- Nếu ta nhìn một cách bình thường trên RAM thì chẳng thấy được gì cả. Nhưng, điều quan trọng là cần biết bên trong nó hoạt động như thế nào. Đây chính là điều tôi muốn hướng dẫn các bạn.
- Dưới đây là một biểu đồ về cách hoạt động của RAM, nó cực kì đơn giản. Nếu bạn nắm được biểu đồ này thì điều đó vô cùng tốt đối với bạn

<img width="400" alt="image" src="https://github.com/minchangggg/Advanced_C/assets/125820144/061540b9-46a4-407b-8fe6-60a3a8c5eeaa"> 

- Như bạn thấy, nó được chia làm 2 cột:
  
        + Một cột địa chỉ (address): địa chỉ là một số cho phép máy tính có thể xác đinh vị trí trong RAM. Nó bắt đầu từ địa chỉ 0 và kết thúc ở địa chỉ 3 448 765 900 126... Hic, tôi không hề biết rõ số lượng địa chỉ chứa trong RAM, tôi chỉ biêt rằng nó có rất nhiều. Bởi vì nó phụ thuộc vào dung lượng bộ nhớ mà bạn có. Chỉ có thể nói là, bạn có RAM, bạn có thể để vào đó nhiều thứ.
        + Và mỗi địa chỉ chứa một giá trị (một số, value): Máy tính của bạn đưa vào RAM những số này để có thể nhớ ngay lập tức. Và người ta chỉ có thể đưa vào một số cho một địa chỉ trong RAM!
