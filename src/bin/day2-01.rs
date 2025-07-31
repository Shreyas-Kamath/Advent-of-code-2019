fn main() {
    let lines = std::fs::read_to_string("data.txt").unwrap();

    let mut list: Vec<i32> = lines
    .split(',')
    .map(|s| s.parse::<i32>().unwrap())
    .collect();

    for c in (0..list.len()).step_by(4) {
        let lhs = list[c + 1] as usize;
        let rhs = list[c + 2] as usize;
        let result = list[c + 3] as usize;

        match list[c] {
            1 => list[result] = list[lhs] + list[rhs],
            2 => list[result] = list[lhs] * list[rhs],

            _ => break,
        }
    }
    print!("{}", list.first().unwrap());
}