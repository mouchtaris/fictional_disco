# vim: et ts=2 sw=2

module Actions
  module GenerateHeaderFiles
    include Action
    CHD = Impls::ComponentHeaderDetails

    def each_header_file_details(mod_name)
      # TODO mod main header file details
      conf_each_comp(mod_name) do |comp_name, comp|
          yield CHD.new(@conf, mod_name, comp_name)
      end
    end

    def generate_header_files
      conf_each_mod do |mod_name, mod|
        each_header_file_details(mod_name) do |dt|
          Impls::Source.new(@conf, dt).rewrite!
        end
      end
    end
  end
end
