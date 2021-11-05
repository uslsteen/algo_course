use std::io;

fn input_usize() -> usize {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();

    return input.trim().parse().unwrap();
}

fn fact_init(fact: &mut Vec<usize>, perm_size : usize) {

    fact.push(1);
    for i in 1..perm_size + 1 {
        fact.push(fact[i - 1] * i);       
    }
}
 
fn get_permut(fact: &Vec<usize>, perm_size : usize, mut perm_num : usize) -> Vec<usize> {

    let mut i : usize = perm_size;
    let mut digit = [0, 0, 0, 0, 0, 0, 0, 0, 0];
    let mut perm = Vec::new();

    while i > 0 {
        let mut group_perm = perm_num % fact[i - 1];
        let mut index = perm_num % fact[i - 1];
        
        if group_perm == 1 {
            index += 1;
        }
        else {
            group_perm += fact[i - 1];
        }

        perm_num = group_perm;
        let mut pos = 0;
        let mut j : usize = 1;

        while j < perm_size {

            if digit[j] == 0 {
                pos += 1;
            }
            if pos == index {
                digit[j] = 1;
                print!("{}", j);
                perm.push(j);
                break;
            }
            j += 1;
        }
        i -= 1;
    }
    perm
}


fn main() {
    let mut fact = Vec::new();
    let mut perm_size = input_usize();
    let mut perm_num  = input_usize();

    fact_init(&mut fact, perm_size);
    let perm = get_permut(&fact, perm_size, perm_num);

    for perm_it in perm.iter() {
        print!("{}", perm_it);
    }
}

