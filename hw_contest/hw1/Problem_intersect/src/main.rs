
use std::io;

fn input_array(size : usize) -> Vec<i32> {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let mut vec = Vec::new();

    while vec.len() != size {
        vec = input.split_whitespace().map(|s| s.parse().unwrap()).collect();
    }

    vec
}

fn input_usize() -> usize {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();

    return input.trim().parse().unwrap();
}

fn input_i32() -> i32 {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();

    return input.trim().parse().unwrap();
}

fn main() {

    let mut tmp : usize = 0;
    let size1 : usize = input_usize();
    let size2 : usize = input_usize();

    let data1 : Vec<i32> = input_array(size1);
    let mut data2_elem : i32;

    let mut i1 : usize = 0; 
    let mut i2 : usize = 1;
    data2_elem = input_i32();

    while i1 < size1 && i2 < size2 {

        if data1[i1] == data2_elem {
            print!("{} ", data1[i1]);
            i1 += 1; i2 +=1;
            data2_elem = input_i32();
        }
        else if data1[i1] > data2_elem {
            i2 += 1;
            data2_elem = input_i32();
        }
        else {
            i1 += 1;
        }
    }
}
