# vim: et ts=2 sw=2
require "./logging"
require "./logger"
require "./conf_dir_storage"
require "./conf_dir_views"
require "./cmake"
require "./file_views"
require "./line_adder"
require "./sagas"
require "./source_details"
require "./component_details"
require "./component_header_details"
require "./component_source_details"
require "./mod_main_details"
require "./mod_main_source_details"
require "./mod_main_header_details"
require "./source"
require "./actions"

module Impls
  struct CMake
    include ::CMake
    def initialize(@io, @conf)
    end
  end

  struct Source
    include ::Logging
    include ::Source
    def initialize(
      @conf,
      @source_details : SourceDetails
    )
      @logger = Logging.logger_for "Source"

      path = @source_details.path
      log.info "Initializing #{@source_details.path}"
      if File.exists? path
        @lines = File.read_lines path
      else
        @lines = [] of String
      end
    end
  end

  struct ComponentSourceDetails
    include ::ComponentSourceDetails
    def initialize(@conf, @mod_name, @comp_name)
    end
  end

  struct ComponentHeaderDetails
    include ::ComponentHeaderDetails
    def initialize(@conf, @mod_name, @comp_name)
    end
  end

  struct ModMainSourceDetails
    include ::ModMainSourceDetails
    def initialize(@conf, @mod_name)
    end
  end

  struct ModMainHeaderDetails
    include ::ModMainHeaderDetails
    def initialize(@conf, @mod_name)
    end
  end

  module Actions
    struct GenerateCMake
      include ::Actions::GenerateCMake
      def initialize(@conf)
        @logger = Logging.logger_for :GenerateCMake
      end
    end
  end
end

