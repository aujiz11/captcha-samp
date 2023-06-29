# Captcha System

## Introduction

- Hệ thống hiện Captcha cho người chơi, Captcha sẽ được hiện với một dialog (DIALOG_STYLE_INPUT) đơn giản, thật ra thư viện này được tạo ra có thể không có gì mới mẻ hay xịn xò, nhưng nó có thể sẽ giúp ít cho bạn.
- Nếu bạn muốn mang nó về và chỉnh sửa, vui lòng giữ lại tên tác giả vì đây là phép lịch sự tối thiểu.

## Function

Để hiểu cách sử dụng thư viện, vui lòng đọc các chức năng tại đây.

```Captcha_Show(playerid, c_id[], caption[], info[], bool:showcode = true)```
- Chức năng này sẽ tạo ra một dialog Captcha cho người chơi.
>playerid - ID người chơi
> c_id - ID của captcha
> caption[] - tiêu đề của dialog captcha
> info[] - miêu tả thông tin của dialog captcha
> showcode - hiện/ẩn mã captcha trên dialog (true/false)

```Captcha_Close(playerid)```
- Đóng hộp thoại Captcha.

## Credits

- Ausil (aujiz) -  scripting
