# BATTLE OF ROBOTS

1. Pendahuluan
   "Battle of Robots" adalah sebuah permainan berbasis konsol yang dikembangkan menggunakan bahasa pemrograman C++. Permainan ini menunjukkan konsep dasar dari Pemrograman Berorientasi Objek (OOP). Dalam permainan ini, pemain bisa memilih dua robot untuk bertarung, dan hasil pertarungan ditentukan oleh serangan yang dilakukan secara acak.

2. Deskripsi Permainan
   Permainan ini terdiri dari tiga bagian utama:
    - Pemilihan Robot: Pemain memilih dua robot yang akan
      bertarung.
    - Pertarungan: Robot akan saling menyerang secara
      bergantian hingga salah satu robot kalah.
    - Pengumuman Pemenang: Setelah pertarungan selesai
      permainan akan menampilkan robot yang menang.

3. Desain Berorientasi Objek
   Program ini menggunakan tiga kelas utama untuk mengimplementasikan logika permainannya: Robot, Battle, dan Game. Setiap kelas memiliki tanggung jawab yang jelas, membuat kode lebih modular dan mudah dipahami.

   Kelas Robot
   - Tujuan: Mewakili robot individu dengan atribut seperti 
     nama, kesehatan, dan kekuatan serangan.
   - Atribut:
     - robotName: Nama robot.
     - robotHealth: Kesehatan robot.
     - robotAttackPower: Kekuatan serangan maksimum robot.
   - Metode:
     - getRobotName(): Mengembalikan nama robot.
     - getRobotHealth(): Mengembalikan jumlah darah 
       (kesehatan) robot.
     - attack(Robot& target): Menyerang robot lain dan 
       mengurangi kesehatannya dengan jumlah damage acak.
     - isDefeated(): Memeriksa apakah robot telah kalah 
       (kesehatan kurang dari atau sama dengan 0).
   
   Kelas Battle
   - Tujuan: Mengatur pertarungan antara dua robot.
   - Metode:
     - start_fight(Robot &robot1, Robot &robot2): Memulai 
       pertarungan antara dua robot dengan serangan bergantian sampai salah satu robot kalah, lalu mengumumkan pemenangnya.
   
   Kelas Game
   - Tujuan: Mengelola logika permainan secara 
     keseluruhan, termasuk pemilihan robot dan memulai pertarungan.
   - Metode:
      - add_robot(const Robot &robot): Menambahkan robot ke 
        dalam daftar robot yang tersedia di permainan.
      - start_game(): Meminta pemain untuk memilih dua robot 
        untuk bertarung dan memulai pertarungan.

4. Cara Menjalankan Permainan
   Persyaratan
   - Kompiler C++ (misalnya GCC atau IDE seperti 
     Code::Blocks, Visual Studio, atau CLion).

   Langkah-langkah Kompilasi
   Untuk mengkompilasi dan menjalankan permainan, ikuti langkah-langkah berikut:
   - Buka terminal atau command prompt.
   - Navigasi ke direktori tempat file kode sumber (misalnya, 
     robot_game.cpp) disimpan.
   - Gunakan perintah berikut untuk mengkompilasi kode:
     // g++ robot_game.cpp -o robot_game
   - Jalankan program yang sudah dikompilasi menggunakan:
     // ./robot_game

5. Contoh Output
   Ketika Anda menjalankan program, Anda akan melihat output yang serupa dengan berikut ini:
        Choose robots for the battle:
        1. RoboOne
        2. RoboTwo
        3. RoboThree
        Select the first robot (1-3): 1
        Select the second robot (1-3): 2
        
        * Battle Start! *
        RoboOne attacks RoboTwo for 23 damage!
        RoboTwo attacks RoboOne for 14 damage!
        RoboOne attacks RoboTwo for 7 damage!
        ...
        RoboTwo is defeated!
        RoboOne wins!

6. Persyaratan
   - Pustaka Standar C++: Kode ini menggunakan pustaka 
     standar C++ termasuk iostream, vector, cstdlib, dan ctime.
   - Pengacakan Angka: Permainan ini menggunakan angka acak 
     untuk mensimulasikan serangan, dengan menggunakan srand() untuk inisialisasi seed dan rand() untuk menghasilkan damage secara acak.

7. Kesimpulan
   Permainan "Battle of Robots" adalah implementasi sederhana yang menunjukkan prinsip dasar OOP menggunakan kelas dan objek dalam C++. Program ini cocok untuk pemula yang ingin belajar bagaimana mendesain dan mengembangkan program modular menggunakan bahasa C++.