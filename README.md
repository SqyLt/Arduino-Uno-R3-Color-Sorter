# 基于Arduino Uno R3的颜色分拣器 (Color Sorter based on Arduino Uno R3)  

**English:** A project that implements an automatic color sorter using an Arduino Uno R3, a TCS34725 color sensor, and two servo motors. It can identify objects of different colors and sort them into preset different areas.

**中文:** 一个使用Arduino Uno R3、TCS34725颜色传感器和两个舵机实现的自动颜色分拣器项目。它可以识别不同颜色的物体，并将它们分拣到预设的不同区域。

## 项目简介 (Project Introduction)

**English:**
This project aims to build an automated color sorting system specifically designed for small objects like chocolate beans. It utilizes a two-tier servo mechanism:
1.  A top MG90 servo controls a 180-degree rotating turntable with an opening. This turntable handles object feeding, positioning under the TCS34725 color sensor, and dropping the object to the lower tier.
2.  A bottom MG90 servo controls a rotatable chute. Based on the color identified by the sensor, this chute directs the falling object into the correct sorting bin.

**中文:**
本项目旨在搭建一个针对巧克力豆等小物件的自动化颜色分拣系统。它采用一个双层舵机结构：
1.  上层一个MG90舵机控制一个可180度旋转的带开孔转盘。此转盘负责物料的送入、定位到TCS34725颜色传感器下方进行检测，并将物体投放到下一层。
2.  下层另一个MG90舵机控制一个可转动的滑道。根据传感器识别到的颜色，此滑道会将落下的物体导向相应的分拣盒。

## 硬件清单 (Hardware List)

**English:**
1.  **Arduino Uno R3** - Main controller
2.  **TCS34725 Color Sensor Module** - For color recognition
3.  **MG90 Servo Motor x 2** - One for the top turntable, one for the bottom sorting chute
4.  **Jumper Wires** - For connecting modules
5.  **Breadboard (Optional)** - For easy prototyping
6.  **Sorter Mechanical Structure**:
    *   Rotating turntable with an opening (controlled by one servo)
    *   Rotatable chute (controlled by the other servo)
    *   Frame/housing, feeding mechanism, collection bins (user-designed and built)
7.  **Colored Chocolate Beans** (or other similarly sized objects) to be sorted
8.  **5V External Power Supply (Recommended)** - For stable servo operation.

**中文:**
1.  **Arduino Uno R3** - 主控制器
2.  **TCS34725 颜色传感器模块** - 用于颜色识别
3.  **MG90舵机 x 2** - 一个用于上层转盘，一个用于下层分拣滑道
4.  **杜邦线若干** - 用于连接各个模块
5.  **面包板 (可选)** - 方便搭建电路原型
6.  **分拣器机械结构**:
    *   带开口的旋转转盘 (由一个舵机控制)
    *   可旋转的滑道 (由另一个舵机控制)
    *   支架/外壳、进料机构、收集盒 (用户需自行设计制作)
7.  **待分拣的彩色巧克力豆** (或其他类似大小的物体)
8.  **5V外部电源 (推荐)** - 保证舵机稳定工作。

## 软件依赖 (Software Dependencies)

**English:**
1.  **Arduino IDE**: For writing and uploading code.
2.  **Adafruit TCS34725 Library**: Driver library for the TCS34725 color sensor.
    -   Install via Arduino IDE Library Manager (search "Adafruit TCS34725").
3.  **Servo Library**: Arduino's built-in library for servo control.
    -   Usually pre-installed with Arduino IDE.
4.  **Wire Library**: I2C communication library, required by TCS34725.
    -   Usually pre-installed with Arduino IDE.

**中文:**
1.  **Arduino IDE**: 用于编写和上传代码。
2.  **Adafruit TCS34725 Library**: TCS34725颜色传感器的驱动库。
    -   可以通过 Arduino IDE 的库管理器搜索 "Adafruit TCS34725" 并安装。
3.  **Servo Library**: Arduino自带的舵机控制库。
    -   通常随 Arduino IDE 默认安装。
4.  **Wire Library**: I2C通讯库，TCS34725传感器需要。
    -   通常随 Arduino IDE 默认安装。

## 接线说明 (Wiring Instructions)

**English:**

| Component                  | Arduino Uno R3 Pin | Description                                      |
| -------------------------- | ------------------ | ------------------------------------------------ |
| TCS34725 VCC               | 5V                 | Sensor Power                                     |
| TCS34725 GND               | GND                | Sensor Ground                                    |
| TCS34725 SCL               | A5 (SCL)           | I2C Clock Line                                   |
| TCS34725 SDA               | A4 (SDA)           | I2C Data Line                                    |
| Turntable Servo Signal     | D7 (Example)       | Controls the top rotating turntable              |
| Chute Servo Signal         | D8 (Example)       | Controls the bottom sorting chute                |
| Servos VCC                 | 5V (External PSU)  | Servo Power (Recommended: independent supply)    |
| Servos GND                 | GND (Arduino/Ext.) | Servo Ground (Common ground with Arduino)        |

**Note:** Servo pin assignments (D7, D8) are examples; adjust as needed in your code. An independent 5V power supply for servos is highly recommended.

**中文:**

| 组件                | Arduino Uno R3 引脚 | 说明                                          |
| ------------------- | ------------------- | --------------------------------------------- |
| TCS34725 VCC        | 5V                  | 传感器电源                                    |
| TCS34725 GND        | GND                 | 传感器地线                                    |
| TCS34725 SCL        | A5 (SCL)            | I2C 时钟线                                    |
| TCS34725 SDA        | A4 (SDA)            | I2C 数据线                                    |
| 转盘舵机(TurntableServo) 信号线 | D7 (示例)           | 控制上层旋转转盘                               |
| 滑道舵机(ChuteServo) 信号线   | D8 (示例)           | 控制下层分拣滑道                               |
| 舵机 VCC            | 5V (外接电源)       | 舵机电源 (推荐使用独立电源)                     |
| 舵机 GND            | GND (Arduino/外接)  | 舵机地线 (与Arduino共地)                       |

**注意**: 舵机引脚分配 (D7, D8) 仅为示例，请根据你的代码进行调整。强烈建议为舵机提供独立的5V电源。
