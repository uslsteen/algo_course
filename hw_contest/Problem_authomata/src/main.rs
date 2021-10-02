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

fn main() {
    let nomin_num = input_usize();
    let coins : Vec<i32> = input_array(nomin_num);
    let mut reserve : i32 = 0;
    let mut delvry_num : i32 = 0;
    
    for i in 0..nomin_num {
        
        if coins[i] == 5 {
            reserve += 1;
        }
        else {
            delvry_num += (coins[i] - 5) / 5;
        }
    }
    if reserve > delvry_num {
        println!("{}", 0);    
    }
    else {
        println!("{}", delvry_num - reserve);
    }
    
}

