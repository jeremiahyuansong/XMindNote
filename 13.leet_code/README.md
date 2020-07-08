# fucking leetcode
  开始走上刷题的道路，这里按照[cspiration](https://cspiration.com/leetcodeClassification)上的顺序进行刷，有两个好处：一是本身tag的分类更为合理，由简到难，数据结构循序渐进;另外就是每个tag里面的题目都是经过挑选，主要应该是一些典型题，且题目前后有一定的关联，可以抽取成某种模式：
    
      关于模式，设计模式这本书里说，模式就是在生活中常遇到的一类问题，以及这类问题的一些固定解法。
  下面，开始吧。。不一定每个题目都会详细记录，有些屁话想说的就会放在这个里面。其他的我觉得还是主要去看代码里面吧。
 ## 数组(按照顺序记录)

 - [26 删除数组中的重复项目](./26.删除排序数组中的重复项.cpp)
   - 思路：数组有序，主要利用快慢指针删除相邻的相同元素，只保留一个
   - 状态：
     - 开始：慢指针指向开始，快指针指向其后一位
     - 移动：快指针若遇上相同的元素，加快移动一位；直到遇见首个不相等的元素，交换**慢指针位置下一个元素**和当前快指针的元素（之所以是下一个，是因为重复的元素要保留一个）
     - 结束：快指针指向数组尾部
- [27 删除数组中指定元素](27.移除元素.cpp)
  - 思路：数组无序，仍然利用快慢指针
  - 状态：
    - 开始：快慢指针均从0开始
    - 移动：当前快指针所指向元素等于目标元素，加快移动一位；直到遇上首个不等于目标的元素，交换慢指针和快指针位置的元素,然后递增当前的慢指针位置
    - 结束：快指针指向数组尾部 
  - 其他：注意和删除重复元素的进行对比
- [80 删除数组中大于2个的重复项目 至多保留2个](./80.删除排序数组中的重复项-ii.cpp)
  - 思路：对比26 一开始容易去对比quick和slow所指的位置，这样就有很多状态需要维护，而且容易出错；这里采用取巧的方式为：对比quick位置和slow-1位置的元素不同的话就进行替换，这样就保留了至多两个的相同元素。
  - 其他：核心代码(一顿操作猛如虎，一看答案我最土。。。。说的就是这题)
    ```C++
      for (size_t quick = 2; quick < nums.size(); ++quick) {
      // 和之前的26题对比 他的保留两个重复项的状态是由和slow的前一个元素对比完成
      if (nums[quick] != nums[slow - 1]) {
        nums[++slow] = nums[quick];
      }
    }
    ```
- [189 数组中元素循环右移k个位置](./189.旋转数组.cpp)
  - 思路：这个题解法比较多，
    - 常规的暴力法：每次只移动一个位置，last存储下上个位置的变量，但是有超时的情况发生。
    - 新空间法：直接将元素放到一个新的数组中应该在的位置`new[(i+k)%size] = nums[i]`,最后再逐个塞回去
    - 多次旋转：
      ```C++
      // 高端方法 offset =  k % size 个元素会被移动到头部
      // 第一次全部反转 1 2 3 4 5 6 7 -> 7 6 5 4 3 2 1
      // 前offset个反转 7 6 5 4 3 2 1 -> 5 6 7 4 3 2 1
      // 后size-offset个反转 5 6 7 4 3 2 1 -> 5 6 7 1 2 3 4
      if (nums.empty()) return;
      int length = nums.size();
      int offset = k % length;
      Reserver(nums, 0, length - 1);
      Reserver(nums, 0, offset - 1);
      Reserver(nums, offset, length - 1);
      ```
- [41 查找缺失的第一个正整数](./41.缺失的第一个正数.cpp)
  - 思路：首先明确最终返回的结果在[1,length+1]的左闭右闭的区间内，同时对满足这个范围区间的元素，将其swap到他正确的位置上`swap(nums[i], nums[nums[i]-1])`上，最后去遍历判定所有i的位置的数nums[i]，找到第一个 `nums[i]!= i+1`的数，此时的i+1就是缺失的第一个正整数。如果没有找到，那么就是所有元素各司其职，缺失的是length+1。 
- [299 猜数字的游戏](./299.猜数字游戏.cpp)
  - 思路：简单的一题被自己做复杂了，本质就是统计字符出现的次数，然后得到相同字符相同位置的数量和相同字符不同位置的数量。
- [134 加油站](./134.加油站.cpp)
  - 重点状态：判断当前剩余的汽油是否够下一次旅行以及当前的站点是否回到初始加油站
- 跳跃游戏
  - [55](./55.跳跃游戏.cpp)：若i位置可以作为起跳点，那么[i,most_far_index]都可以作为起跳点,其中most_far_index = std::max(most_far_index, i+nums[i]])，在这过程中不断更新most_far_index的位置信息。
  - [45](./45.跳跃游戏-ii.cpp) 思路：利用边界的思想，需要更新step的时候应该是到达边界的时候，到达边界后同时更新最远能够到达的距离
    ```
      // 边界方法:次数的更新是通过到达边界的时候在条件里进行更新
      // 2 3 1 1 4
      // i  maxpos  end  step
      // 0    2      2    1
      // 1    4      2    1
      // 2    4      4    2
      // 3    4      4    2
      // 4    4      4    2
    ```

  ## 字符串
  - [28 实现strStr](./28.实现-str-str.cpp)
    - Sunday算法：
    ```C++
    // Sunday算法 看了官网实现一下，还挺有意思
    // "核心思想"：   通过比较haystack的[idx,idx + len(needle))子串和needle是否相等来寻找
    // "偏移表"：     对于needle模板会建立一个偏移表，存放的是needle中每个字符出现的最右位置+1
    //              这个偏移表后面会用来更新idx起始位置
    // "idx更新逻辑"：传统方法就是依次递增idx，sunday算法对这里进行了优化
    //    a、下一个待匹配位字符haystack[idx+len(needle)+1]不在偏移表中,idx = idx + len(needle) +1
    //       直观理解就是：checkthis和this在[0,4)匹配失败，查看下一个k不在偏移表，直接跳到idx+len(needle)+1
    //    b、下一个待匹配位字符haystack[idx+len(needle)+1]在偏移表中， idx = idx + table['字符']
    //        直观理解就是：因为上一轮不匹配，在所有包含了下一个字符的子串中idx需要偏移的最短的距离
    // 整体来说，优化的点在于利用了上一次不匹配的结果信息来处理内
    ```
    - [14 最长前缀匹配](./14.最长公共前缀.cpp)
      - 思路一：找到长度最短的子串，然后在这个长度范围内对比每一个pos上的元素是否出现不同；
      - 思路二：两两元素依次查找最长公共子串，找到的结果再和下一个进行查找
      - 思路三：利用字典序对比（代码简洁，效率不咋地）
    - [58 最后一个单词的长度](./58.最后一个单词的长度.cpp)
      - 思路：利用标准库find_last_of 注意处理最后一个是空格的情况
    - [387 字符串中第一个唯一字符](./387.字符串中的第一个唯一字符.cpp)
      - 思路：利用数组进行26个小写字母的映射 并统计出现次数 然后遍历找到第一个为1的index
    - [383 赎金信](./383.赎金信.cpp)
      - 思路：还是利用数组进行26个字母的映射 统计次数并比对大小
    - [344 反转字符串](./344.反转字符串.cpp)
      - 思路：原地反转找到中点 交换两边的元素
        ```C++
        char temp;
        size_t length = s.size();
        for (size_t i = 0; i < length / 2; ++i) {
          temp = s[i];
          s[i] = s[length - i - 1];
          s[length - i - 1] = temp;
        }
        ```
    - [151 翻转字符串里的单词](./151.翻转字符串里的单词.cpp)
      - 思路： 根据空格提取出所有的单词放到vector中，然后对vector进行输出
    - [345 反转字符串中的元音字母](./345.反转字符串中的元音字母.cpp)
      - 思路： 首尾分别用指针进行元音字母的查找，找到就进行替换，直到首尾指针相遇
    - [290 单词规律](./290.单词规律.cpp)
      - 思路：首先是一种通用的字符串分割的实现方式，分割完之后利用两个unordered_map进行对比
    ```c++
      void split(const string &source, const string &split, vector<string> &result) {
        string::size_type start, end;
        start = 0;
        end = source.find(split);
        while (end != string::npos) {
          result.push_back(source.substr(start, end - start));
          // 更新起始和终止的位置
          start = end + split.size();
          end = source.find(split, start);  // 这里的find从新的start位置开始查找
        }
        // 处理剩余的串
        if (start < source.size()) result.push_back(source.substr(start));
      }
    ```
    - [205 同构字符串](./205.同构字符串.cpp)
      - 思路：利用hash table比对出现的同一字符的位置
    - [242 有效的字母异位词](./242.有效的字母异位词.cpp)
      - 思路：还是利用数组进行hash映射统计字母的个数 但是这里可以优化只适用一个数组即可，对s字串和t字串分别在对应位置进行递增和递减操作，最终判定对应字母位置是否有非0出现。
    - [49 字母异位词分组](./49.字母异位词分组.cpp)
      - 思路：对字符串数组里的每个元素进行sort然后添加到hash map中，利用c++的emplace_back和move特性
    - [87 扰乱字符串](./87.扰乱字符串.cpp)
      - 思路：
        - 假设S拆分为S1和S2，T拆分为T1和T2，那么若要T成为S的扰乱字符串，则有`(S1==T1&&S2==T2) || (S1==T2&&S2==T1)`
        - 拆分的位置可以在任意位置
        - 通过递归方式解决问题
    - [179 最大数](./179.最大数.cpp)
      - 思路：最直接的思路是对number进行字典序的逆序输出，但是无法解决[3,30]被输出为303的问题，看了答案之后了解到需要定义新的sort规则：若a_b > b_a,则有a>b，其中“_”表示字符串连接
    - [38 外观数列](./38.外观数列.cpp)
      - 思路：按照轮次遍历上一次字符串结果，统计其中相同数字的个数并更新到当前这轮的字符串结果。注意：在for中嵌套while的套路通常可以用来快速统计。
      ```C++
      // for 这里不做index的递增更新，而是由内部while循环来做
      for (auto index = 0; index < last_str.size();) {
        auto last_ch = last_str[index];
        auto count = 0;
        // while主要用作相等条件的判定 同时前面需要携带index的结束条件
        while (index < last_str.size() && last_str[index] == last_ch) {
          ++index;
          ++count;
        }
        cur_str += (to_string(count) + last_ch);
      }   
      ```

      ```c++
      // 另外一种形式
      for (auto index = 0; index < last_str.size(); ++index) {
        auto count = 0;
        while(index + 1 < last_str.size() && last_str[index] == last_str[index+1]) {
          count++;
          index++;
        }
        cur_str += (to_string(count) + last_str[index]);
      }
      ```
    - [316 删除重复字符使返回字符串字典序最小](./316.去除重复字母.cpp)
      - 思路: 遍历字符串，遇到不同字符时，判定与栈顶元素的大小关系，若遍历字符比栈顶元素小，且后续的字符串中还存在重复的栈顶元素，那么将栈顶的元素pop出去。这个操作结束的条件为：栈空 || 栈顶元素已经不存在重复 || 栈顶元素比遍历元素小，因此，采用的是while循环,关键的状态代码如下：
     
        ```C++
        for (size_t i = 0; i < s.size(); ++i) {
        count[s[i] - 'a']--;
        if (res_set.count(s[i]) != 0) continue;
        // 单调栈状态更新：非空、栈顶元素大于当前遍历s[i]、后续还有该字母
        while (!res_stack.empty() && res_stack.top() > s[i] && count[res_stack.top() - 'a'] > 0) {
          res_set.erase(res_stack.top());
          res_stack.pop();
        }
        res_stack.push(s[i]);
        res_set.emplace(s[i]);
        }
        ``` 
      
      - 优化：
        - 上面方法采用了一个hash表判断重复，但由于这里只有26个小写字符，可以替换为一个bool的visit数组；
        - 采用stack的方式，后续从stack中取结果的时候，因为只能使用top的方法取，取出来之后还需要reverse翻转，可以优化为直接使用**string代替stack**，back操作代替top操作。效果相同，且最后避免翻转。
