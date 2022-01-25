
//4 people
public int solution(int N, string S)
        {
            int num = 1;
            int count = 0;
            List list = new List();
            list = S.Split(' ').ToList();
            while(num<=N) {
                if (list.Where(x => x.Contains(num + "B") || x.Contains(num + "C")|| x.Contains(num + "D")|| x.Contains(num + "E")).FirstOrDefault() == null)
                {
                    list.AddRange(new List{num + "B", num + "C",num + "D" , num + "E"});
                    count++;
                }

                if (list.Where(x=> x.Contains(num + "F") || x.Contains(num + "G")|| x.Contains(num + "H")|| x.Contains(num + "J")).FirstOrDefault()==null)
                {
                    list.AddRange(new List{num + "F", num + "G",num + "H" , num + "J"});
                    count++;
                }

                if (list.Where(x=> x.Contains(num + "D") || x.Contains(num + "E")|| x.Contains(num + "F")|| x.Contains(num + "G")).FirstOrDefault()==null)
                {
                    list.AddRange(new List{num + "D", num + "E",num + "F" , num + "G"});
                    count++;
                }

                num++;
            }

            return count;
        }