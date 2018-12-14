#include <string>
#include <type_traits>

namespace sms
{
    namespace model
    {
        //
        // Tags
        //
        struct TName{};
        namespace tversion
        {
            struct TMajor{};
            struct TMinor{};
            struct TPatch{};
        }
        struct TVersion{};
        template <size_t> struct TPath{};
        struct TProject{};
        struct TModule{};
        struct TComp{};
        template <typename, typename> struct TBelong{};
        template <typename, typename> struct TDep{};

        //
        // Data
        //
        template <typename T, typename... D> using tagged = std::tuple<T, D...>;
        //
        using Name = tagged<TName, std::string>;
        namespace version
        {
            using namespace tversion;
            using _val_t = std::uint16_t;
            using Major = tagged<TMajor, _val_t>;
            using Minor = tagged<TMinor, _vat_t>;
            using Patch = tagged<TPatch, _val_t>;
        }
        using Version = tagged<TVersion,
            version::Major,
            version::Minor,
            version::Patch
            >;

        template <size_t N> using Path = tagged<TPath, std::array<N, std::string>>;
        using Project = tagged<TProject, Name, Version, Path>;
        using Module = tagged<TModule, Name, Version>;
        using Comp = tagged<TComp, Name>;

        using ProjectName = tagged<TProject, Name>;
        using ModuleName = tagged<TModule, Name>;
        using CompName = tagged<TComp, Name>;

        template <typename A, typename B> using Belong = tagged<TBelong, A, B>;

        template <typename> struct make__tc;
        template <typename T, typename... D> struct make__tc<tagged<T, D...>>
        {
            static tagged<T, D...> call(D&&... data)
            {
                return { T{}, std::forward<D>(data)... };
            }
        };

        template <typename T, typename... Args>
        T make(Args&&... args)
        {
            return make__tc<T>::call(std::forward<Args>(args)...);
        }
    }

    namespace fixture
    {
        using namespace model;

        auto Smaragd()
        {
            auto major = make<version::Major>(0);
            auto minor = make<version::Minor>(0);
            auto patch = make<version::Patch>(0);
            auto version = make<Version>(
                    std::move(major),
                    std::move(minor),
                    std::move(patch)
                );
            return version;
        }
    }
}
