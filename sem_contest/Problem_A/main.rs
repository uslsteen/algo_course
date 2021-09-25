use std::io;

fn input_array(arr: &mut[i32; 23]) -> i32 {

    let mut total: i32 = 0;

    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let vec : Vec<&str> = input.split(' ').collect();

    let mut i: i32 = 0;

    for vec_it in vec.iter() {
        arr[i as usize] = vec_it.trim().parse().unwrap();
        total += arr[i as usize];
        i += 1; 
    }

    return total; 
}


fn main() {

    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let num_of_stones: i32 = input.trim().parse().unwrap();
    
    let mut w_arr: [i32; 23] = [0; 23];
    let mut total: i32 = input_array(&mut w_arr);
    
    let combin_num: i32 = 1 << num_of_stones;
    let mut min: i32 = i32::MAX;

    for gen in 0..combin_num {

        let mut sum: i32 = 0;
        let mut i: usize = 0;
        let mut u: i32 = gen;

        while u != 0 {
            sum += (u & 1) * w_arr[i];
            i += 1;
            u >>= 1;
        }

        let mut diff: i32 = total - sum - sum;

        if diff < 0 {
            diff = -diff;
        }
        if diff < min {
            min = diff;
        }
    }

    println!("{}", min);
}
