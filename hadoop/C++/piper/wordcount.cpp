#include <string>
#include <vector>
using namespace std;
 
#include <hadoop/Pipes.hh>
#include <hadoop/StringUtils.hh>
#include <hadoop/TemplateFactory.hh>
 
class WordCountMapper : public HadoopPipes::Mapper {
 
    public:
 
        WordCountMapper(HadoopPipes::TaskContext& context) {}
 
        void map(HadoopPipes::MapContext& context)
        {
            vector<string> words = HadoopUtils::splitString(context.getInputValue(), " ");
            for(unsigned int i = 0; i < words.size(); ++i)
                context.emit(words[i], "1");
        }
};
 
class WordCountReducer : public HadoopPipes::Reducer {
 
    public:
 
        WordCountReducer(HadoopPipes::TaskContext& context) {}
 
        void reduce(HadoopPipes::ReduceContext& context)
        {
            int sum = 0;
 
            while (context.nextValue())
                sum += HadoopUtils::toInt(context.getInputValue());
 
            context.emit(context.getInputKey(), HadoopUtils::toString(sum));
        }
};
 
int main(void)
{
    return HadoopPipes::runTask(HadoopPipes::TemplateFactory<WordCountMapper, WordCountReducer>());
}
