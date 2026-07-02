import tkinter as tk

# --- ฟังก์ชันคำนวณ ---
expression = ""

def press(num):
    global expression
    expression = expression + str(num)
    equation.set(expression)

def equalpress():
    global expression
    try:
        total = str(eval(expression))
        equation.set(total)
        expression = total
    except ZeroDivisionError:
        equation.set("หารด้วย 0 ไม่ได้")
        expression = ""
    except:
        equation.set(" ข้อผิดพลาด ")
        expression = ""

def clear():
    global expression
    expression = ""
    equation.set("")

# --- ส่วนสร้างหน้าต่าง GUI ---
root = tk.Tk()
root.title("เครื่องคิดเลข")
root.geometry("320x450")
root.configure(bg="#202020")

equation = tk.StringVar()

# ช่องแสดงผล
display = tk.Entry(root, textvariable=equation, font=("Arial", 22), bd=0, 
                   justify="right", bg="#2d2d2d", fg="#ffffff")
display.grid(columnspan=4, ipady=20, padx=10, pady=15, sticky="nsew")

# ปุ่มกด
buttons = [
    ('7', 1, 0), ('8', 1, 1), ('9', 1, 2), ('/', 1, 3),
    ('4', 2, 0), ('5', 2, 1), ('6', 2, 2), ('*', 2, 3),
    ('1', 3, 0), ('2', 3, 1), ('3', 3, 2), ('-', 3, 3),
    ('C', 4, 0), ('0', 4, 1), ('=', 4, 2), ('+', 4, 3),
]

for (text, row, col) in buttons:
    if text in ['/', '*', '-', '+', '=']:
        btn_bg, btn_fg = "#ff9500", "#ffffff"
    elif text == 'C':
        btn_bg, btn_fg = "#a5a5a5", "#000000"
    else:
        btn_bg, btn_fg = "#333333", "#ffffff"
        
    if text == '=':
        action = equalpress
    elif text == 'C':
        action = clear
    else:
        action = lambda x=text: press(x)
        
    btn = tk.Button(root, text=text, font=("Arial", 14, "bold"), 
                    bg=btn_bg, fg=btn_fg, borderwidth=0, command=action)
    btn.grid(row=row, column=col, padx=5, pady=5, sticky="nsew")

# ตั้งค่าตำแหน่งให้ขยายเต็มหน้าต่าง
for i in range(4):
    root.columnconfigure(i, weight=1)
for i in range(1, 5):
    root.rowconfigure(i, weight=1)

# เปิดโปรแกรม
root.mainloop()