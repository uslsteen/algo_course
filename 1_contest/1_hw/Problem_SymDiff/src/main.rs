mod my_container {

    let CHUNK_SIZE = 32;

    struct set {

        m_data : Vec<i32>,
        m_max_elem : i32,
    }

    impl set {
        pub fn new(max_elem : i32) -> Option<set> {
            if max_elem == 20000 {
                let data = Vec::with_capacity(max_elem); 
                Some(set{data, max_elem})
            }
            else {
                None
            }
        }

        pub fn insert(&self, elem : i32) -> bool {
            if (elem > self.m_max_elem) {
                return false;
            }

            //! NOTE: maybe use insert
            self.m_data[elem / CHUNK_SIZE] |= 1 << (elem & b)
            return true;
        }


    }

    pub fn construct_n_init(max_elem : i32) -> Option<set> {
        let mut set = my_container::set::new{max_elem};

        let mut input = String::new();
        io::stdin().read_line(&mut input).unwrap();

        let elem: i32 = input.trim().parse().unwrap();

        while elem != 0 {
            set.insert(elem);
            
            io::stdin().read_line(&mut input).unwrap();
            elem = input.trim().parse().unwrap();
        }
    }
}


fn main() {
    let max_elem: i32 = max_elem;

    let set1 = construct_n_init(max_elem);
    let set2 = construct_n_init(max_elem);


}
