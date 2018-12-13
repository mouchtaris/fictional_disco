# vim: et ts=2 sw=2

module Actions
  module GenerateSourceFiles
    include Action
    CSD = Impls::ComponentSourceDetails
    MSD = Impls::ModMainSourceDetails

    def each_source_file_details(mod_name)
      yield MSD.new(@conf, mod_name)

      conf_each_comp(mod_name) do |comp_name, comp|
        yield CSD.new(@conf, mod_name, comp_name)
      end
    end

    def generate_source_files
      conf_each_mod do |mod_name, mod|
        each_source_file_details(mod_name) do |dt|
          Impls::Source.new(@conf, dt).rewrite!
        end
      end
    end
  end
end
