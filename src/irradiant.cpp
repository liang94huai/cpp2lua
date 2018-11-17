#include "DumpVisitor.hpp"
#include "DumpConsumer.hpp"
#include "DumpAction.hpp"

static cl::opt<bool> BakeIncludes("bake-includes", cl::init(false), cl::NotHidden,
    cl::desc("Controls whether includes should be baked into the resulting script."));

int main(int argc, char const** argv)
{
    llvm::cl::OptionCategory category("irradiant");
    // Ugly hack to get around there being no easy way of adding arguments
    std::vector<char const*> arguments(argv, argv + argc);
    if (strcmp(arguments.back(), "--") == 0)
        arguments.pop_back();
    arguments.push_back("-extra-arg=-fno-builtin");
    arguments.push_back("-extra-arg=-nostdlib");
    arguments.push_back("-extra-arg=-nostdinc");
    arguments.push_back("-extra-arg=-Ishim/c");
    arguments.push_back("--");

    int size = (int)arguments.size();
    CommonOptionsParser parser(size, arguments.data(), category);

    ClangTool tool(parser.getCompilations(), parser.getSourcePathList());
    return tool.run(newFrontendActionFactory<DumpAction>().get());
}
